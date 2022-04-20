/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/20 11:19:50 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->a_phl + 2)
	{
		if (pthread_mutex_init(&table->m_arr[i], NULL) != 0)
			return (1);
	}
	return (0);
}

void	mutex_dest(t_table *table)
{
	int	i;

	i = -1;
	while (&table->m_arr[++i] != NULL && i < table->a_phl + 2)
		pthread_mutex_destroy(&table->m_arr[i]);
}

int	cleaner(char *pr_name, t_table *table, t_philo *philo)
{
	if (table)
	{
		if (table->m_arr)
		{
			mutex_dest(table);
			free(table->m_arr);
		}
		if (table->t_arr)
			free(table->t_arr);
	}
	if (philo)
		free(philo);
	if (pr_name)
		perror(pr_name);
	return (0);
}
