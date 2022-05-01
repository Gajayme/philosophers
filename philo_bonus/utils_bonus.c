/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:44:15 by lyubov            #+#    #+#             */
/*   Updated: 2022/04/30 22:45:44 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_semclose(t_philo *philo)
{
	sem_close(philo->sem_f);
	sem_close(philo->sem_p);
	sem_close(philo->sem_d);
}

int	cleaner(char *pr_name, t_philo *philo)
{
	if (philo)
	{
		ft_semclose(philo);
		if (philo->t_arr)
			free(philo->t_arr);
		if (philo->id_arr)
			free (philo->id_arr);
	}
	if (pr_name)
		perror(pr_name);
	exit (1);
}
