/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:23:58 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/22 12:14:41 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_frk);
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m)
		&& !pthread_mutex_unlock(philo->l_frk))
		return ;
	printf("%ld %d has taken a fork\n", timer(philo->tbl->t_strt),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	pthread_mutex_lock(philo->r_frk);
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m)
		&& !pthread_mutex_unlock(philo->r_frk))
		return ;
	printf("%ld %d has taken a fork\n", timer(philo->tbl->t_strt),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
}

void	even_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_frk);
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m)
		&& !pthread_mutex_unlock(philo->r_frk))
		return ;
	printf("%ld %d has taken a fork\n", timer(philo->tbl->t_strt),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	pthread_mutex_lock(philo->l_frk);
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m)
		&& !pthread_mutex_unlock(philo->l_frk))
		return ;
	printf("%ld %d has taken a fork\n", timer(philo->tbl->t_strt),
		philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m))
		return ;
	printf("%ld %d is eating\n", timer(philo->tbl->t_strt), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	philo->is_e = 1;
	waiter(philo->tbl->t_eat);
	pthread_mutex_unlock(philo->l_frk);
	pthread_mutex_unlock(philo->r_frk);
	gettimeofday(&philo->lst_sm, NULL);
	philo->lst_m = count_time(philo->lst_sm);
	philo->num_e += 1;
	if (philo->num_e == philo->tbl->eat_num)
		philo->is_f = 1;
	philo->is_e = 0;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m))
		return ;
	printf("%ld %d is sleeping\n", timer(philo->tbl->t_strt), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
	waiter(philo->tbl->t_slp);
	pthread_mutex_lock(philo->sto_m);
	if (philo->tbl->is_d && !pthread_mutex_unlock(philo->sto_m))
		return ;
	printf("%ld %d is thinking\n", timer(philo->tbl->t_strt), philo->id_p);
	pthread_mutex_unlock(philo->sto_m);
}

// void	thinking(t_philo *philo)
// {

// }
