/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:54 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/29 20:53:53 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	adder(char *arg, int flag, int *to_write)
{
	int	num;

	if (up_isdigit(arg) != 0 && !up_putstr_fd(arg, 2)
		&& !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	num = up_atoi(arg);
	if (((flag && (num > INT_MAX || num < 1))
			|| (!flag && (num > INT_MAX || num < 1)))
		&& !up_putstr_fd(arg, 2) && !up_putstr_fd(" :invalid arg\n", 2))
		return (1);
	*to_write = num;
	return (0);
}

void	sem_prepare(t_table *table)
{
	table->sem = sem_open ("fork_Sem", O_CREAT | O_EXCL, 0644, table->a_phl);
	printf("inited\n");
}

int	valid(char **av, t_table *table)
{
	int	i;

	i = 1;
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
	table->is_d = 0;
	table->fed_ph = 0;
	sem_prepare(table);
	table->t_arr = (pthread_t *)malloc(sizeof(pthread_t) * table->a_phl);
	if (!table->t_arr)
		return (1);
	memset(table->t_arr, 0, sizeof(pthread_t) * table->a_phl);
	return (0);
}
