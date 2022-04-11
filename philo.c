/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/11 13:36:13 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	printf("hello from thread number %d\n", philo.idx_philo);
	sleep(1);
	return (NULL);
}

void	philo_fill(t_table *table, t_philo *philo, int i)
{
	(*philo).idx_philo = i;
	(*philo).left_fork = table->mutex_arr[i];
	if (i == 0)
		(*philo).right_fork = table->mutex_arr[table->am_philo - 1];
	else
		(*philo).right_fork = table->mutex_arr[i - 1];
	(*philo).time_die = table->time_die;
	(*philo).time_eat = table->time_eat;
	(*philo).time_sleep = table->time_sleep;
	(*philo).time_without_eat = table->time_without_eat;
}

void	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;

	//malloc part
	philo = (t_philo *)up_malloc(sizeof(t_philo) * table->am_philo);
	table->mutex_arr = (pthread_mutex_t *)up_malloc(sizeof(pthread_mutex_t) * table->am_philo);
	table->threads = (pthread_t *)up_malloc(sizeof(pthread_t) * table->am_philo);
	printf ("malloced\n");

	i = -1;
	while (++i < table->am_philo)
	{
		philo_fill(table, &philo[i], i);
		if (pthread_create(&table->threads[i], NULL, &routine, (void *)&philo[i]) != 0)
			up_perror("Can't create thread", table, philo);
	}
	printf("\nnum philo = %d\n\n", table->am_philo);
	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			up_perror("Can't join thread", table, philo);
		printf("joining %d\n", i);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac < 5 && up_putstr_fd("Invalid arguments\n", 2))
		exit (1);
	valid(av, &table);
	//printf("1=%d\n2=%d\n3=%d\n4=%d\n5=%d\n", table.am_philo, table.time_die, table.time_eat, table.time_sleep, table.time_without_eat);
	thread_manager(&table);
}
