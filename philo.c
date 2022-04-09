/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/09 21:17:25 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	printf("hello from thread\n");
	if (arg)
		return (NULL);
	return (NULL);
}

void	thread_manager(t_philo *data)
{
	int	i;

	data->mutex_arr = (pthread_mutex_t *)up_malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->threads = (pthread_t *)up_malloc(sizeof(pthread_t) * data->num_philo);
	i = -1;
	printf ("malloced\n");
	while (i++ < data->num_philo - 1)
	{
		pthread_mutex_init(&data->mutex_arr[i], NULL);
		printf("mUTEX %d INITED\n", i);
	}
	i = -1;
	while (i++ < data->num_philo)
	{
		if (pthread_create(&data->threads[i], NULL, &routine, NULL) != 0)
		{
			perror("THread create error");
			exit (1);
		}
	}
	i = -1;
	while (i++ < data->num_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
		{
			perror("THread create error");
			exit (1);
		}
	}
}

int	main(int ac, char **av)
{
	t_philo	data;

	if (ac < 5)
	{
		up_putstr_fd("Invalid arguments\n", 2);
		exit (1);
	}
	valid(av, &data);
	printf("1=%d\n2=%d\n3=%d\n4=%d\n5=%d\n", data.num_philo, data.time_die, data.time_eat, data.time_sleep, data.time_without_eat);
	thread_manager(&data);
}