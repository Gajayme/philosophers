/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/20 16:40:30 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	while (!philo->tbl->is_d && ((philo->tbl->t_eat && philo->num_e < philo->tbl->eat_num)
        || (!philo->tbl->eat_num)))
	{
		pthread_mutex_lock(philo->sto_m);
		printf("%ld %d is thinking\n", timer(philo->tbl->t_str), philo->id_p);
		pthread_mutex_unlock(philo->sto_m);
		if (philo->tbl->is_d)
			break ;
		take_fork(philo);
		if (philo->tbl->is_d)
			break ;
		eating(philo);
		pthread_mutex_unlock(philo->l_frk);
		pthread_mutex_unlock(philo->r_frk);
		if (philo->tbl->is_d)
			break ;
		sleeping(philo);
	}
	//printf("philo %d is over\n", philo->id_p);
	return (NULL);
}

void	philo_fill(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->a_phl)
	{
		philo[i].tbl = table;
		philo[i].id_p = i + 1;
		philo[i].lst_m = table->t_str;
		philo[i].l_frk = &table->m_arr[i];
		if (i == 0)
			philo[i].r_frk = &table->m_arr[table->a_phl - 1];
		else
			philo[i].r_frk = &table->m_arr[i - 1];
		philo[i].sto_m = &table->m_arr[table->a_phl];
		philo[i].is_e = FALSE;
		philo[i].num_e = 0;
	}
}

int	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;
	//fix
	gettimeofday(&table->t_tbl, NULL);
	table->t_str = count_time(table->t_tbl);
	//fix
	if (memory_manager(&philo, table))
		return (1);
	philo_fill(table, philo);
	i = -1;
	while (++i < table->a_phl)
	{
		if (pthread_create(&table->t_arr[i], NULL, &routine, &philo[i])
			&& !cleaner("philo", table, philo))
			return (1);
	}
	while (!table->is_d)
	{
		while (--i > -1 && !table->is_d)
			if (!philo->is_e && timer(philo->lst_m) > table->t_die
				&& ((!table->eat_num) || (table->eat_num || philo->num_e < table->eat_num)))
		{
			printf("PHILO %d DIE!!\n", i + 1);
			table->is_d = 1;
		}

		i = table->a_phl;
	}
	while (--i >= 0)
	{
		if (pthread_join(table->t_arr[i], NULL)
			&& !cleaner("philo", table, philo))
			return (1);
	}
	cleaner(NULL, table, philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac < 5 || ac > 6) && !up_putstr_fd("Invalid amount of arguments\n", 2))
		return (1);
	if (valid(av, &table))
		return (1);
	if (thread_manager(&table))
		return (1);
	return (0);
}
