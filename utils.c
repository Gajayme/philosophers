/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:16:46 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/16 16:22:08 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//IT COULD BE AN ERROR
void	mutex_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->am_philo)
	{
		//printf("Initing %d mutex\n", i);
		pthread_mutex_init(&table->mutex_arr[i], NULL);
	}
}

void	mutex_dest(t_table *table)
{
	int	i;

	i = -1;
	while (&table->mutex_arr[++i] != NULL && i < table->am_philo)
	{
		//printf("Destroing %d mutex\n", i);
		pthread_mutex_destroy(&table->mutex_arr[i]);
	}
}

// void	thread_join(t_table *table, t_philo *philo)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < table->am_philo && table->threads[i])
// 	{
// 		if (pthread_join(table->threads[i], NULL) != 0)
// 			up_perror(NULL, "philo", table, philo);
// 	}
// }

void	up_perror(char *err_msg, char *pr_name, t_table *table, t_philo *philo)
{
	if (table)
	{
		if (table->mutex_arr)
		{
			mutex_dest(table);
			free(table->mutex_arr);
		}
		if (table->threads)
			free(table->threads);
	}
	if (philo)
		free(philo);
	if (err_msg && !pr_name)
		up_putstr_fd(err_msg, 2);
	else if (!err_msg && pr_name)
		perror(pr_name);
	exit (1);
}
