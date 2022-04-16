/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/16 21:26:16 by gajayme          ###   ########.fr       */
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

//TIPS:
//1. detach thread if we can't join in
//2. no exit!!!
//3. stdout mutex; last meal mutex
//4. must die
//5. init vars to custom sleep in struct

//should all time vars be LONG LONG
typedef struct s_philo
{
	int				idx_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_without_eat;
	long long		time_start;
	long long		time_now;
	struct timeval	time_philo;
	struct timeval	last_meal;
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
	struct timeval	time_table;
	pthread_mutex_t	*mutex_arr;
	pthread_t		*threads;
}		t_table;

//main
void	get_time(long long *time);
void	thread_manager(t_table *table);
void	philo_fill(t_table *table, t_philo *philo);

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
void	up_perror(char *err_msg, char *pr_name, t_table *table, t_philo *philo);

//time utils
long	timer(long start);
void	waiter(int time);

//activities
int		take_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
