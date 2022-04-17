/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/17 15:58:56 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time(long long *time)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	*time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
}

void	*routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	//get_time(&philo.time_start);
	while (1)
	{
		take_fork(&philo);
		eating(&philo);
		pthread_mutex_unlock(philo.left_fork);
		pthread_mutex_unlock(philo.right_fork);
		sleeping(&philo);
	}
	return (NULL);
}

void	philo_fill(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		philo[i].idx_philo = i + 1;
		philo[i].left_fork = &table->mutex_arr[i];
		if (i == 0)
			philo[i].right_fork = &table->mutex_arr[table->am_philo - 1];
		else
			philo[i].right_fork = &table->mutex_arr[i - 1];
		philo[i].time_die = table->time_die;
		philo[i].time_eat = table->time_eat;
		philo[i].time_sleep = table->time_sleep;
		philo[i].time_without_eat = table->time_without_eat;
		// if we want make mutual time
		philo[i].time_start = table->time_table.tv_sec * 1000 + table->time_table.tv_usec / 1000;
	}
}

int	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;

	//im here
	if (memory_manager(&philo, table))
		return (1);
	gettimeofday(&table->time_table, NULL);
	philo_fill(table, philo);
	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_create(&table->threads[i], NULL, &routine, (void *)&philo[i]) != 0)
			up_perror(NULL, "philo", table, philo);
	}
	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			up_perror(NULL, "philo", table, philo);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac < 5 || ac > 6) && !up_putstr_fd("Invalid amount of arguments\n", 2))
		return (1);
	if (valid(av, &table))
		return (1);
	if (thread_manager(&table))
		return (1);
	return (0);
}
