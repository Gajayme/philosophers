/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:41 by gajayme           #+#    #+#             */
/*   Updated: 2022/06/15 20:43:56 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	if (philo->ev)
		usleep(philo->tbl->t_eat * 700);
	while (!philo->is_f)
	{
		if (philo->ev && even_fork(philo))
			break ;
		if (!philo->ev && odd_fork(philo))
			break ;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
	}
	pthread_mutex_lock(philo->sto_m);
	philo->tbl->fed_ph += 1;
	pthread_mutex_unlock(philo->sto_m);
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
		philo[i].lst_m = table->t_strt;
		philo[i].l_frk = &table->m_arr[i];
		if (i == 0)
			philo[i].r_frk = &table->m_arr[table->a_phl - 1];
		else
			philo[i].r_frk = &table->m_arr[i - 1];
		philo[i].sto_m = &table->m_arr[table->a_phl];
		philo[i].is_e = 0;
		philo[i].is_f = 0;
		philo[i].num_e = 0;
		if (i & 1)
			philo[i].ev = 1;
		else
			philo[i].ev = 0;
	}
}

void	life_circle(t_philo *philo, t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->a_phl)
		{
			pthread_mutex_lock(&table->m_arr[table->a_phl]);
			if (!philo[i].is_e && !philo[i].is_f
				&& (timer(philo[i].lst_m) > table->t_die))
			{
				table->is_d = 1;
				printf("%s%ld %d died%s\n",CRED, timer(table->t_strt), i + 1, CRED);
				pthread_mutex_unlock(&table->m_arr[table->a_phl]);
				return ;
			}
			else if (philo->tbl->fed_ph == philo->tbl->a_phl)
				return ;
			pthread_mutex_unlock(&table->m_arr[table->a_phl]);
		}
		usleep(10);
	}
	pthread_mutex_unlock(&table->m_arr[table->a_phl]);
}

int	thread_manager(t_table *table)
{
	int		i;
	t_philo	*philo;

	if (memory_manager(&philo, table))
		return (1);
	i = -1;
	gettimeofday(&table->t_tbl, NULL);
	table->t_strt = count_time(table->t_tbl);
	philo_fill(table, philo);
	while (++i < table->a_phl)
	{
		if (pthread_create(&table->t_arr[i], NULL, &routine, &philo[i])
			&& !cleaner("philo", table, philo))
			return (1);
		if (table->a_phl == 1)
			pthread_detach(table->t_arr[i]);
	}
	life_circle(philo, table);
	if (table->a_phl == 1 && !cleaner(NULL, table, philo))
		return (0);
	if (joiner(philo, table))
		return (1);
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
