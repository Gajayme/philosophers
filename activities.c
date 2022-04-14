/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student->42->fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:28:18 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/13 13:53:48 by gajayme          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_odd(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->left_fork))
		printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
	if (!pthread_mutex_lock(philo->right_fork))
		printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
	return (0);
}

int	fork_even(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->right_fork))
		printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
	if (!pthread_mutex_lock(philo->left_fork))
		printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
	return (0);
}

int	eating(t_philo *philo)
{
	//printf("%ldms %d is eating\n", timer(philo->time_start), philo->idx_philo);
	waiter(philo->time_eat);
	return (0);
}