/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/30 23:45:10 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_manager(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, philo_monitor, NULL))
	{
		sem_post(philo->sem_d);
		sem_wait(philo->sem_p);
		exit(1);
	}

	printf("in philo %d\n", philo->n_phl);
	//sleep(1);
	exit(0);
}

void	proc_manager(t_philo *philo)
{
	int	i;

	i = -1;
	while(++i < philo->a_phl)
	{
		philo->n_phl = i + 1;
		philo->id_arr[i] = fork();
		if (philo->id_arr[i] == 0)
			philo_manager(philo);
		else if(philo->id_arr[i] == -1)
		{
			while(i-- >= 0)
				kill(philo->id_arr[i], SIGKILL);
			cleaner("philo_bonus", philo);

		}
	}
	//sleep(1);
	//printf("finished\n");
	//exit(0);

}

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac < 5 || ac > 6) && !up_putstr_fd("Invalid amount of arguments\n", 2))
		return (1);
	if (valid(av, &philo))
		return (1);
	proc_manager(&philo);
	sem_wait(philo.sem_d);
	printf("ending\n");
	return (0);
}
