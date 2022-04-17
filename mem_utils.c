/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:26:14 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/17 15:58:49 by gajayme          ###   ########.fr       */
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
		up_perror(NULL, "philo", table, philo);
		return (NULL);
	}
	up_bzero(p, size);
	return (p);
}

//check here
int	memory_manager(t_philo **philo, t_table *table)
{
	*philo = (t_philo *)up_calloc(sizeof(t_philo) * table->am_philo, NULL, NULL);
	if (!philo && !up_perror(NULL, "philo", table, philo))
		return (1);
	table->mutex_arr = (pthread_mutex_t *)up_calloc(sizeof(pthread_mutex_t)
			* table->am_philo, table, *philo);
	if (!table->mutex_arr && !up_perror(NULL, "philo", table, philo))
		return(1);
	if (mutex_init(table) && !up_perror(NULL, "philo", table, philo))
		return (1);
	table->threads = (pthread_t *)up_calloc(sizeof(pthread_t)
			* table->am_philo, table, *philo);
	if (!table->threads && !up_perror(NULL, "philo", table, philo))
		return(1);
	return (0);
}
