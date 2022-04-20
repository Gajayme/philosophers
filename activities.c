/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:23:58 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/20 12:15:24 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->id_p % 2 == 1)
	{
		pthread_mutex_lock(philo->l_frk);
		pthread_mutex_lock(philo->sto_m);
		printf("%ld %d has taken left fork\n", timer(philo->tbl->t_str),
			philo->id_p);
		pthread_mutex_unlock(philo->sto_m);
		pthread_mutex_lock(philo->r_frk);
		pthread_mutex_lock(philo->sto_m);
		printf("%ld %d has taken right fork\n", timer(philo->tbl->t_str),
			philo->id_p);
		pthread_mutex_unlock(philo->sto_m);
		return (0);
	}
	pthread_mutex_lock(philo->r_frk);
	pthread_mutex_lock(philo->sto_m);
	printf("%ld %d has taken right fork\n", timer(philo->tbl->t_str),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	pthread_mutex_lock(philo->l_frk);
	pthread_mutex_lock(philo->sto_m);
	printf("%ld %d has taken left fork\n", timer(philo->tbl->t_str),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	return (0);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->sto_m);
	printf("%ld %d is eating\n", timer(philo->tbl->t_str), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	philo->is_e = TRUE;
	waiter(philo->tbl->t_eat);
	philo->is_e = FALSE;
	gettimeofday(&philo->lst_sm, NULL);
	philo->lst_m = count_time(philo->lst_sm);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->sto_m);
	printf("%ld %d is sleeping\n", timer(philo->tbl->t_str), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	waiter(philo->tbl->t_slp);
	//he must think in the beginning
	pthread_mutex_lock(philo->sto_m);
	printf("%ld %d is thinking\n", timer(philo->tbl->t_str), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
}
