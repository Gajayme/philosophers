/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/11 13:32:24 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*up_malloc(size_t	size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		exit (1);
	return (p);
}

void	up_perror(char *err_msg, t_table *table, t_philo *philo)
{
	if (table->mutex_arr)
		free(table->mutex_arr);
	if (table->threads)
		free(table->threads);
	if (philo)
		free(philo);
	perror(err_msg);
	exit (1);
}
