/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/12 01:08:44 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	if (philo.idx_philo % 2 == 0)
		pthread_mutex_lock(philo.left_fork);
	else
		pthread_mutex_lock(philo.right_fork);
	printf("hello from thread number %d\n", philo.idx_philo);
	sleep(2);
	if (philo.idx_philo % 2 == 0)
		pthread_mutex_unlock(philo.left_fork);
	else
		pthread_mutex_unlock(philo.right_fork);
	return (NULL);
}

void	philo_fill(t_table *table, t_philo *philo, int i)
{
	philo->idx_philo = i;
	philo->left_fork = &table->mutex_arr[i];
	if (i == 0)
		philo->right_fork = &table->mutex_arr[table->am_philo - 1];
	else
		philo->right_fork = &table->mutex_arr[i - 1];
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->time_sleep = table->time_sleep;
	philo->time_without_eat = table->time_without_eat;
}

void	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)up_calloc(sizeof(t_philo) * table->am_philo, NULL, NULL);
	table->mutex_arr = (pthread_mutex_t *)up_calloc(sizeof(pthread_mutex_t) * table->am_philo, table, philo);
	mutex_init(table);
	table->threads = (pthread_t *)up_calloc(sizeof(pthread_t) * table->am_philo, table, philo);
	i = -1;
	while (++i < table->am_philo)
	{
		philo_fill(table, &philo[i], i);
		if (pthread_create(&table->threads[i], NULL, &routine, (void *)&philo[i]) != 0)
			up_perror(NULL, "Philo", table, philo);
	}
	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			up_perror(NULL, "Philo", table, philo);
		//printf("joining %d\n", i);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac < 5 || ac > 6) && !up_putstr_fd("Invalid amount of arguments\n", 2))
		return (1);
	valid(av, &table);
	thread_manager(&table);
}
