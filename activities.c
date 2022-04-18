/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:23:58 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/18 12:56:56 by lyubov           ###   ########.fr       */
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
	pthread_mutex_lock(philo->stdo_mut);
	printf("%ldms %d is eating\n", timer(philo->time_start), philo->idx_philo);
	//here
	gettimeofday(philo->last_meal, NULL);
	//here
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
