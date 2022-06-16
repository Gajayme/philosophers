/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/06/15 20:50:08 by lyubov           ###   ########.fr       */
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

# define CGRN "\x1B[32m"
# define CRED "\x1B[31m"
# define CWHT "\x1B[37m"
# define CCYN "\x1B[36m"
# define CMAG "\x1B[35m"

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
void	philo_fill(t_table *table, t_philo *philo);
void	life_circle(t_philo *philo, t_table *table);
int		thread_manager(t_table *table);

//valid
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_table *table);

//lib_utils
long	up_atoi(const char *str);
int		up_isdigit(char *arg);
int		up_putstr_fd(char *s, int fd);

//utils
int		mutex_init(t_table *table);
int		joiner(t_philo *philo, t_table *table);
void	mutex_dest(t_table *table);
int		cleaner(char *pr_name, t_table *table, t_philo *philo);

//time utils
long	count_time(struct timeval time);
long	timer(long start);
void	waiter(int time);

//memory_utils
void	up_bzero(void *s, size_t n);
void	*up_calloc(size_t size, t_table *table, t_philo *philo);
int		memory_manager(t_philo **philo, t_table *table);

//activities
int		odd_fork(t_philo *philo);
int		even_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);

#endif
