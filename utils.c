/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/12 01:03:25 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		//printf("Initing %d mutex\n", i);
		pthread_mutex_init(&table->mutex_arr[i], NULL);
	}
}

void	mutex_dest(t_table *table)
{
	int	i;

	i = -1;
	while (&table->mutex_arr[++i] != NULL && i < table->am_philo)
	{
		//printf("Destroing %d mutex\n", i);
		pthread_mutex_destroy(&table->mutex_arr[i]);
	}
}

void	up_perror(char *err_msg, char *prog_name, t_table *table, t_philo *philo)
{
	if (table)
	{
		if (table->mutex_arr)
			free(table->mutex_arr);
		if (table->threads)
			free(table->threads);
	}
	if (philo)
		free(philo);
	if (err_msg && !prog_name)
		up_putstr_fd(err_msg, 2);
	else if (!err_msg && prog_name)
		perror(prog_name);
	exit (1);
}
