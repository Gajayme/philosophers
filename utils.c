/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/14 20:14:08 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//IT COULD BE AN ERROR
void	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		//printf("Initing %d mutex\n", i);
		pthread_mutex_init(&table->mutex_arr[i], NULL);
	}
}

void	mutex_dest(t_table *table)
{
	int	i;

	i = -1;
	while (&table->mutex_arr[++i] != NULL && i < table->am_philo)
	{
		//printf("Destroing %d mutex\n", i);
		pthread_mutex_destroy(&table->mutex_arr[i]);
	}
}

void	up_perror(char *err_msg, char *prog_name, t_table *table, t_philo *philo)
{
	if (table)
	{
		if (table->mutex_arr)
			free(table->mutex_arr);
		if (table->threads)
			free(table->threads);
	}
	if (philo)
		free(philo);
	if (err_msg && !prog_name)
		up_putstr_fd(err_msg, 2);
	else if (!err_msg && prog_name)
		perror(prog_name);
	exit (1);
}

//IT COULD BE AN ERROR
long	timer(long time_start)
{
	long			time_passed;
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	time_passed = (time_now.tv_sec * 1000 + time_now.tv_usec / 1000) - time_start;
	return (time_passed);
}

void	waiter(int time)
{
	useconds_t		time_to_wait;
	struct timeval	start_eat;
	struct timeval	now_eat;

	gettimeofday(&start_eat, NULL);
	time_to_wait = time * 1000;
	usleep ((time_to_wait * 95) / 100);
	gettimeofday(&now_eat, NULL);
	while (((now_eat.tv_sec * 1000000 + now_eat.tv_usec)
			- (start_eat.tv_sec * 1000000 + start_eat.tv_usec)) > time_to_wait)
	{
		usleep(1);
		gettimeofday(&now_eat, NULL);
	}
}
