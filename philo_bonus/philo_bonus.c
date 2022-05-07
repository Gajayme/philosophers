/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/05/07 20:17:23 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_manager(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, philo_monitor, philo))
	{
		sem_wait(philo->sem_p);
		perror("philo_bonus");
		sem_post(philo->sem_d);
		exit (1);
	}
	pthread_detach(monitor);
	life_circle(philo);
}

void	proc_manager(t_philo *philo)
{
	int	i;

	i = -1;
	gettimeofday(&philo->t_philo, NULL);
	philo->t_strt = count_time(philo->t_philo);
	philo->t_lmeal = philo->t_strt;
	while (++i < philo->a_phl)
	{
		philo->n_phl = i + 1;
		philo->id_arr[i] = fork();
		if (philo->id_arr[i] == 0)
			philo_manager(philo);
		else if (philo->id_arr[i] == -1)
		{
			while (i-- >= 0)
				kill(philo->id_arr[i], SIGKILL);
			cleaner("philo_bonus", philo);
		}
	}
}

void	*fed_monitor(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = ((t_philo *)arg);
	i = 0;
	while (++i < philo->a_phl)
		sem_wait(philo->sem_fed);
	sem_post(philo->sem_d);
	return (NULL);
}

void	main_monitoring(t_philo *philo)
{
	pthread_t	main_mon;

	if (pthread_create(&main_mon, NULL, fed_monitor, philo))
	{
		sem_wait(philo->sem_p);
		perror("philo_bonus");
		sem_post(philo->sem_d);
		return ;
	}
	pthread_detach(main_mon);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac < 5 || ac > 6) && !up_putstr_fd("Invalid amount of arguments\n", 2))
		return (1);
	if (valid(av, &philo))
		return (1);
	proc_manager(&philo);
	main_monitoring(&philo);
	sem_wait(philo.sem_d);
	killing(&philo);
	cleaner(NULL, &philo);
	return (0);
}
