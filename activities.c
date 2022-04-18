/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:23:58 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/18 20:43:46 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->idx_philo % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->stdo_mut);
		printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
		pthread_mutex_unlock(philo->stdo_mut);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->stdo_mut);
		printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
		pthread_mutex_unlock(philo->stdo_mut);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
	pthread_mutex_unlock(philo->stdo_mut);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
	pthread_mutex_unlock(philo->stdo_mut);
	return (0);
}

void	eating(t_philo *philo)
{
	struct timeval last_meal;
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d is eating\n", timer(philo->time_start), philo->idx_philo);
	gettimeofday(&last_meal, NULL);
	philo->last_meal = count_time(last_meal);
	pthread_mutex_unlock(philo->stdo_mut);
	waiter(philo->time_eat);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d is sleeping\n", timer(philo->time_start), philo->idx_philo);
	pthread_mutex_unlock(philo->stdo_mut);
	waiter(philo->time_sleep);
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d is thinking\n", timer(philo->time_start), philo->idx_philo);
	pthread_mutex_unlock(philo->stdo_mut);
}
