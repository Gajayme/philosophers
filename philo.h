/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/12 00:59:49 by gajayme          ###   ########.fr       */
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
	int				idx_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_without_eat;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}		t_philo;

typedef struct s_table
{
	int				am_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_without_eat;

	pthread_mutex_t	*mutex_arr;
	pthread_t		*threads;
}		t_table;

//main
void	thread_manager(t_table *table);
void	philo_fill(t_table *table, t_philo *philo, int i);

//valid
int		adder(char *arg, int flag);
void	valid(char **av, t_table *table);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);
void	up_bzero(void *s, size_t n);
void	*up_calloc(size_t size, t_table *table, t_philo *philo);
//utils
void	mutex_dest(t_table *table);
void	mutex_init(t_table *table);
void	up_perror(char *err_msg, char *prog_name, t_table *table, t_philo *philo);

#endif
