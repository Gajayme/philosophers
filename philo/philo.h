/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/29 20:05:43 by lyubov           ###   ########.fr       */
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
//2. Do i need eating flag
//3. Int activities

typedef struct s_table
{
	int				a_phl;
	int				is_d;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				eat_num;
	int				fed_ph;
	long			t_strt;
	long			t_now;
	struct timeval	t_tbl;
	pthread_mutex_t	*m_arr;
	pthread_t		*t_arr;
}		t_table;

typedef struct s_philo
{
	t_table			*tbl;
	int				id_p;
	int				ev;
	int				is_e;
	int				num_e;
	int				is_f;
	struct timeval	lst_sm;
	long			lst_m;
	pthread_mutex_t	*l_frk;
	pthread_mutex_t	*r_frk;
	pthread_mutex_t	*sto_m;
}		t_philo;

//main
void	*routine(void *arg);
void	life_circle(t_philo *philo, t_table *table);
int		thread_manager(t_table *table);
void	philo_fill(t_table *table, t_philo *philo);

//valid
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_table *table);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);

//utils
int		joiner(t_philo *philo, t_table *table);
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
int		even_fork(t_philo *philo);
int		odd_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);

#endif