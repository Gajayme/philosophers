/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/20 12:33:23 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define TRUE 1
# define FALSE 0
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
// USE COUNT TIME!!!!
//should all time vars be LONG LONG

typedef struct s_table
{
	int				a_phl;
	int				is_d;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				eat_num;
	long			t_str;
	long			t_now;
	struct timeval	t_tbl;
	pthread_mutex_t	*m_arr;
	pthread_t		*t_arr;
}		t_table;

typedef struct s_philo
{
	int				id_p;
	int				is_e;
	t_table			*tbl;
	struct timeval	lst_sm;
	long			lst_m;
	pthread_mutex_t	*l_frk;
	pthread_mutex_t	*r_frk;
	pthread_mutex_t	*sto_m;
}		t_philo;

//main
void	*routine(void *arg);
int		thread_manager(t_table *table);
void	philo_fill(t_table *table, t_philo *philo);
void	philo_fill(t_table *table, t_philo *philo);

//valid
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
long	count_time(struct timeval time);

//memory_utils
int		memory_manager(t_philo **philo, t_table *table);
void	up_bzero(void *s, size_t n);
void	*up_calloc(size_t size, t_table *table, t_philo *philo);

//activities
int		take_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
