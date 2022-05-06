/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/05/05 18:45:33 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	adder(char *arg, int flag, int *to_write)
{
	int	num;

	if (up_isdigit(arg) != 0 && !up_putstr_fd(arg, 2)
		&& !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	num = up_atoi(arg);
	if (((flag && (num > INT_MAX || num < 1))
			|| (!flag && (num > INT_MAX || num < 1)))
		&& !up_putstr_fd(arg, 2) && !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	*to_write = num;
	return (0);
}

int	sem_prepare(t_philo *philo)
{
	philo->sem_f = sem_open ("sem_f", O_CREAT, 0644, philo->a_phl);
	if (philo->sem_f == SEM_FAILED)
		return (1);
	sem_unlink("sem_f");
	philo->sem_p = sem_open ("sem_p", O_CREAT, 0644, 1);
	if (philo->sem_p == SEM_FAILED)
		return (1);
	sem_unlink("sem_p");
	philo->sem_d = sem_open ("sem_d", O_CREAT, 0644, 0);
	if (philo->sem_d == SEM_FAILED)
		return (1);
	sem_unlink("sem_d");
	philo->sem_fed = sem_open ("sem_fed", O_CREAT, 0644, 0);
	if (philo->sem_fed == SEM_FAILED)
		return (1);
	sem_unlink("sem_fed");
	return (0);
}

int	valid(char **av, t_philo *philo)
{
	int	i;

	i = 1;
	philo->eat_num = -1;
	philo->is_fed = 0;
	philo->is_eat = 0;
	if (adder(av[i++], 1, &philo->a_phl))
		return (1);
	if (adder(av[i++], 0, &philo->t_die))
		return (1);
	if (adder(av[i++], 0, &philo->t_eat))
		return (1);
	if (adder(av[i++], 0, &philo->t_slp))
		return (1);
	if (av[i] && adder(av[i++], 0, &philo->eat_num))
		return (1);
	if (sem_prepare(philo))
		return (1);
	philo->id_arr = (int *)malloc(philo->a_phl);
	philo->t_arr = (pthread_t *)malloc(sizeof(pthread_t) * philo->a_phl);
	if (!philo->id_arr || !philo->t_arr)
		cleaner ("philo_bonus", philo);
	memset(philo->t_arr, 0, sizeof(pthread_t) * philo->a_phl);
	return (0);
}
