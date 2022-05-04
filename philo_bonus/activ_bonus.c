/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activ_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:13:51 by lyubov            #+#    #+#             */
/*   Updated: 2022/05/04 15:35:05 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_monitor(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	while (1)
	{
		usleep(10);
		sem_wait(philo->sem_p);
		if (philo->is_fed)
		{
			sem_post(philo->sem_fed);
			sem_post(philo->sem_p);
			break ;
		}
		else if (!philo->is_eat && (timer(philo->t_lmeal) > philo->t_die))
		{
			printf("%ld %d dead\n", timer(philo->t_strt), philo->n_phl);
			sem_post(philo->sem_d);
			break ;
		}
		sem_post(philo->sem_p);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	sem_wait(philo->sem_f);
	sem_wait(philo->sem_p);
	printf("%ld %d taken a fork\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	sem_wait(philo->sem_f);
	sem_wait(philo->sem_p);
	printf("%ld %d taken a fork\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	sem_wait(philo->sem_p);
	gettimeofday(&philo->s_lmeal, NULL);
	philo->t_lmeal = count_time(philo->s_lmeal);
	philo->is_eat = 1;
	printf("%ld %d eating\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	waiter(philo->t_eat);
	sem_wait(philo->sem_p);
	philo->is_eat = 0;
	sem_post(philo->sem_p);
	sem_post(philo->sem_f);
	sem_post(philo->sem_f);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->sem_p);
	printf("%ld %d sleeping\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	waiter(philo->t_slp);
	sem_post(philo->sem_f);
	sem_post(philo->sem_f);
	sem_wait(philo->sem_p);
	printf("%ld %d thinking\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
}

void	life_circle(t_philo *philo)
{
	if (philo->n_phl % 2)
		usleep(philo->t_eat * 700);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		if (philo->eat_num)
		{
			sem_wait(philo->sem_p);
			philo->eat_num -= 1;
			if (!philo->eat_num)
				philo->is_fed = 1;
			sem_post(philo->sem_p);
		}
	}
}
