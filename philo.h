/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/18 12:53:15 by lyubov           ###   ########.fr       */
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
//3. last meal mutex
//4. must die
//5. init vars to custom sleep in struct

//should all time vars be LONG LONG
typedef struct s_philo
{
	int				idx_philo;
	int				*ph_dead;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_without_eat;
	long long		time_start;
	long long		time_now;
	struct timeval	time_philo;
	struct timeval	*last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*stdo_mut;
}		t_philo;

typedef struct s_table
{
	int				am_philo;
	int				tb_dead;
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
int		thread_manager(t_table *table);
void	philo_fill(t_table *table, t_philo *philo);

//__valid__
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_table *table);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);
//utils
void	mutex_dest(t_table *table);
int		mutex_init(t_table *table);
int		cleaner(char *pr_name, t_table *table, t_philo *philo);

//time utils
long	timer(long start);
void	waiter(int time);

//memory_utils
int		memory_manager(t_philo **philo, t_table *table);
void	up_bzero(void *s, size_t n);
void	*up_calloc(size_t size, t_table *table, t_philo *philo);

//activities
int		take_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
