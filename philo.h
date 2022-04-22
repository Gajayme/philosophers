/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/22 20:44:13 by gajayme          ###   ########.fr       */
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
//3. last meal mutex
//5.
//6. make 2 take forks
//should all time vars be LONG LONG

typedef struct s_table
{
	int				a_phl;
	int				is_d;
	int				is_cr;
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
//int	take_fork(t_philo *philo);
void	even_fork(t_philo *philo);
void	odd_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

#endif
