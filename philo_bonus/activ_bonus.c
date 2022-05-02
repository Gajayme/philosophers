/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activ_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:13:51 by lyubov            #+#    #+#             */
/*   Updated: 2022/05/02 14:23:34 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_monitor(t_philo *philo)
{
	// printf("time to eat %d\n", philo->t_eat);
	// usleep(philo->t_eat);
	// printf("done monitoring\n");
	while (1)
	{
		usleep(10);
		//printf("hereeeee!!!\n");
		sem_wait(philo->sem_p);
		if (philo->is_fed)
		{
			sem_post(philo->sem_fed);

			sem_post(philo->sem_p);
			break;
		}
		else if (!philo->is_eat && (timer(philo->t_lmeal) > philo->t_die))
		{
			//philo->is_ded = 1;
			printf("%ld %d dead\n", timer(philo->t_strt),philo->n_phl);
			//sem_wait(philo->sem_p);
			sem_post(philo->sem_d);

			sem_post(philo->sem_p);
			break;
		}
		printf("here\n");
		sem_post(philo->sem_p);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	sem_wait(philo->sem_p);
	sem_wait(philo->sem_f);
	printf("%ld %d taken a fork\n", timer(philo->t_strt),philo->n_phl);
	sem_post(philo->sem_p);
	sem_wait(philo->sem_p);
	sem_wait(philo->sem_f);
	printf("%ld %d taken a fork\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	sem_wait(philo->sem_p);
	//philo->is_eat = 1;
	printf("%ld %d eating\n", timer(philo->t_strt), philo->n_phl);
	sem_post(philo->sem_p);
	waiter(philo->t_eat);
	//unprotected data
	philo->is_eat = 0;
	philo->t_lmeal = count_time(&philo->t_philo);
	//
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
	if(philo->n_phl % 2)
		usleep(philo->eat_num * 700);
	while (philo->eat_num != 0)
	{
		eating(philo);
		//printf("start eating\n");
		if (philo->eat_num)
			philo->eat_num -= 1;
		//printf("finished eating\n");
		sleeping(philo);
	}
	//printf("puk\n");
	philo->is_fed = 1;
	sem_post(philo->sem_fed);
	exit(0);
}
