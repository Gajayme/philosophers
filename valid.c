/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/17 14:22:29 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	adder(char *arg, int flag, int *to_write)
{
	int	num;

	if (up_isdigit(arg) != 0 && up_putstr_fd(arg, 2)
		&& up_putstr_fd(" :invalid arg\n", 2))
		return(1);
	num = up_atoi(arg);
	if (((flag && (num > INT_MAX || num < 1))
			|| (!flag && (num > INT_MAX || num < 1)))
		&& !up_putstr_fd(arg, 2) && !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	*to_write = num;
	return(0);
}

int	valid(char **av, t_table *table)
{
	int	i;

	i = 1;
	table->threads = NULL;
	table->mutex_arr = NULL;
	table->time_without_eat = 0;
	if (adder(av[i++], 1, &table->am_philo))
		return (1);
	if (adder(av[i++], 0, &table->time_die))
		return (1);
	if (adder(av[i++], 0, &table->time_eat))
		return (1);
	if (adder(av[i++], 0, &table->time_sleep))
		return (1);
	if (av[i] && adder(av[i++], 0, &table->time_without_eat))
		return (1);
	return (0);
}
