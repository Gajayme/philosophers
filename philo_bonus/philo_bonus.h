/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/05/04 15:38:13 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <signal.h>
# include <semaphore.h>

//need to check funcks in header
typedef struct s_philo
{
	int				n_phl;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				a_phl;
	int				eat_num;
	int				is_fed;
	int				is_eat;
	int				*id_arr;
	long			t_strt;
	long			t_lmeal;
	struct timeval	s_lmeal;
	struct timeval	t_philo;
	sem_t			*sem_fed;
	sem_t			*sem_f;
	sem_t			*sem_p;
	sem_t			*sem_d;
	pthread_t		*t_arr;
}		t_philo;

//main
void	philo_manager(t_philo *philo);
void	proc_manager(t_philo *philo);
void	*fed_monitor(void *arg);
void	main_monitoring(t_philo *philo);

//valid
int		sem_prepare(t_philo *philo);
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_philo *philo);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);
void	killing(t_philo *philo);

//utils
void	ft_semcloser(t_philo *philo);
int		cleaner(char *pr_name, t_philo *philo);
long	count_time(struct timeval time);
long	timer(long start);
void	waiter(int time);

//activ
void	philo_manager(t_philo *philo);
void	life_circle(t_philo *philo);
void	eating(t_philo *philo);
void	*philo_monitor(void *arg);

#endif
