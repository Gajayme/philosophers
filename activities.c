/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:23:58 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/16 20:31:57 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->idx_philo % 2 == 1)
	{
		if (!pthread_mutex_lock(philo->left_fork))
			printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
		if (!pthread_mutex_lock(philo->right_fork))
			printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
		return (0);
	}
	if (!pthread_mutex_lock(philo->right_fork))
		printf("%ldms %d has taken right fork\n", timer(philo->time_start), philo->idx_philo);
	if (!pthread_mutex_lock(philo->left_fork))
		printf("%ldms %d has taken left fork\n", timer(philo->time_start), philo->idx_philo);
	return (0);
}

void	eating(t_philo *philo)
{
	printf("%ldms %d is eating\n", timer(philo->time_start), philo->idx_philo);
	waiter(philo->time_eat);
}

void	sleeping(t_philo *philo)
{
	printf("%ldms %d is sleeping\n", timer(philo->time_start), philo->idx_philo);
	waiter(philo->time_sleep);
}
