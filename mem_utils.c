/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:26:14 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/20 12:07:07 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	up_bzero(void *s, size_t n)
{
	char	*arr;

	arr = s;
	while (n --)
		*arr++ = '\0';
}

void	*up_calloc(size_t size, t_table *table, t_philo *philo)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		cleaner("philo", table, philo);
		return (NULL);
	}
	up_bzero(p, size);
	return (p);
}

int	memory_manager(t_philo **philo, t_table *table)
{
	*philo = NULL;
	*philo = (t_philo *)up_calloc(sizeof(t_philo) * table->a_phl, NULL, NULL);
	if (!philo && !cleaner("philo", table, *philo))
		return (1);
	table->m_arr = (pthread_mutex_t *)up_calloc(sizeof(pthread_mutex_t)
			* (table->a_phl + 2), table, *philo);
	if (!table->m_arr && !cleaner("philo", table, *philo))
		return (1);
	if (mutex_init(table) && !cleaner("philo", table, *philo))
		return (1);
	table->t_arr = (pthread_t *)up_calloc(sizeof(pthread_t)
			* table->a_phl, table, *philo);
	if (!table->t_arr && !cleaner("philo", table, *philo))
		return (1);
	return (0);
}
