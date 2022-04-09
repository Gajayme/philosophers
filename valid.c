/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/09 18:31:09 by gajayme          ###   ########.fr       */
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

void	valid(char **av, t_philo *data)
{
	int	i;

	i = 1;
	data->num_philo = adder(av[i++], 1);
	data->time_die = adder(av[i++], 0);
	data->time_eat = adder(av[i++], 0);
	data->time_sleep = adder(av[i++], 0);
	if (!av[i])
		data->time_without_eat = 0;
	else
		data->time_without_eat = adder(av[i++], 0);
}
