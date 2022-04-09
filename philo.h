/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/09 20:44:43 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>

# define MAX_THREADS 512

typedef struct s_philo
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_without_eat;

	pthread_mutex_t	*mutex_arr;
	pthread_t		*threads;
}		t_philo;

void	*up_malloc(size_t	size);
void	thread_manager(t_philo *data);
int		up_putstr_fd(char *s, int fd);
long	up_atoi(const char *str);
int		up_isdigit(char *arg);
void	valid(char **av, t_philo *data);
int		adder(char *arg, int flag);

#endif