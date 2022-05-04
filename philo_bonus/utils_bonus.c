/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:44:15 by lyubov            #+#    #+#             */
/*   Updated: 2022/05/04 15:10:54 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_semclose(t_philo *philo)
{
	int	i;

	i = -1;
	sem_close(philo->sem_f);
	sem_close(philo->sem_p);
	sem_close(philo->sem_d);
	while (++i < philo->a_phl)
		sem_post(philo->sem_fed);
	sem_close(philo->sem_fed);
}

int	cleaner(char *pr_name, t_philo *philo)
{
	if (philo)
	{
		ft_semclose(philo);
		if (philo->t_arr)
			free(philo->t_arr);
		if (philo->id_arr)
			free (philo->id_arr);
	}
	if (pr_name)
	{
		perror(pr_name);
		exit (1);
	}
	exit (0);
}

long	count_time(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	timer(long start)
{
	long			passed;
	struct timeval	now;

	gettimeofday(&now, NULL);
	passed = (now.tv_sec * 1000 + now.tv_usec / 1000) - start;
	return (passed);
}

void	waiter(int time)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	usleep (time * 950);
	gettimeofday(&now, NULL);
	while (((now.tv_sec * 1000 - start.tv_sec * 1000)
			+ (now.tv_usec / 1000 - start.tv_usec / 1000)) < time)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}
