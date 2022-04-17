/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/17 15:57:04 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//IT COULD BE AN ERROR
int	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		if (pthread_mutex_init(&table->mutex_arr[i], NULL) != 0)
			return (1);
	}
	return(0);
}

void	mutex_dest(t_table *table)
{
	int	i;

	i = -1;
	while (&table->mutex_arr[++i] != NULL && i < table->am_philo)
		pthread_mutex_destroy(&table->mutex_arr[i]);
}

int	up_perror(char *err_msg, char *pr_name, t_table *table, t_philo *philo)
{
	if (table)
	{
		if (table->mutex_arr)
		{
			mutex_dest(table);
			free(table->mutex_arr);
		}
		if (table->threads)
			free(table->threads);
	}
	if (philo)
		free(philo);
	if (err_msg && !pr_name)
		up_putstr_fd(err_msg, 2);
	else if (!err_msg && pr_name)
		perror(pr_name);
	return (0);
}
