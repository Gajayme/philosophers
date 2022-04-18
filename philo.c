/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/18 20:47:57 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		sleeping(philo);
	}
	return (NULL);
}

//do i really nedd pointer to table struct???
void	philo_fill(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		philo[i].idx_philo = i + 1;
		philo[i].ph_dead = &table->tb_dead;
		philo[i].time_die = table->time_die;
		philo[i].time_eat = table->time_eat;
		philo[i].time_sleep = table->time_sleep;
		philo[i].time_without_eat = table->time_without_eat;
		philo[i].time_start = count_time(table->time_table);
		philo[i].left_fork = &table->mutex_arr[i];
		philo[i].last_meal = count_time(table->time_table);
		if (i == 0)
			philo[i].right_fork = &table->mutex_arr[table->am_philo - 1];
		else
			philo[i].right_fork = &table->mutex_arr[i - 1];
		philo[i].stdo_mut = &table->mutex_arr[table->am_philo];
	}
}

int	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;

	if (memory_manager(&philo, table))
		return (1);
	philo_fill(table, philo);
	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_create(&table->threads[i], NULL, &routine, &philo[i])
		&& !cleaner("philo", table, philo))
			return (1);
	}
	while (1)
	{
		sleep(1);
		while (--i > -1)
			printf("\nlast meal = %lld\n\n", philo[i].last_meal);
		i = table->am_philo;
	}
	while (--i >= 0)
	{
		if (pthread_join(table->threads[i], NULL)
		&& !cleaner("philo", table, philo))
			return (1);
	}
	cleaner(NULL, table, philo);
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
