/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/21 18:15:28 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	adder(char *arg, int flag, int *to_write)
{
	int	num;

	if (up_isdigit(arg) != 0 && up_putstr_fd(arg, 2)
		&& up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	num = up_atoi(arg);
	if (((flag && (num > INT_MAX || num < 1))
			|| (!flag && (num > INT_MAX || num < 1)))
		&& !up_putstr_fd(arg, 2) && !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	*to_write = num;
	return (0);
}

int	valid(char **av, t_table *table)
{
	int	i;

	i = 1;
	table->t_arr = NULL;
	table->m_arr = NULL;
	table->eat_num = 0;
	if (adder(av[i++], 1, &table->a_phl))
		return (1);
	if (adder(av[i++], 0, &table->t_die))
		return (1);
	if (adder(av[i++], 0, &table->t_eat))
		return (1);
	if (adder(av[i++], 0, &table->t_slp))
		return (1);
	if (av[i] && adder(av[i++], 0, &table->eat_num))
		return (1);
	table->is_cr = 0;
	table->is_d = 0;
	table->t_arr = NULL;
	table->m_arr = NULL;
	return (0);
}
