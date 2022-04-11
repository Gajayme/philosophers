/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/12 00:47:30 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	adder(char *arg, int flag)
{
	int	num;

	if (up_isdigit(arg) != 0 && up_putstr_fd(arg, 2)
		&& up_putstr_fd(" :invalid arg\n", 2))
		exit (1);
	num = up_atoi(arg);
	if (((flag && (num > MAX_THREADS || num < 1))
			|| (!flag && num > INT_MAX) || num < 0)
		&& !up_putstr_fd(arg, 2) && !up_putstr_fd(" :invalid arg\n", 2))
		exit (1);
	return (num);
}

void	valid(char **av, t_table *table)
{
	int	i;

	i = 1;
	table->am_philo = adder(av[i++], 1);
	table->time_die = adder(av[i++], 0);
	table->time_eat = adder(av[i++], 0);
	table->time_sleep = adder(av[i++], 0);
	if (!av[i])
		table->time_without_eat = 0;
	else
		table->time_without_eat = adder(av[i++], 0);
	//table->mutex_arr = NULL;
	table->threads = NULL;
}
