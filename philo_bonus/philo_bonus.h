/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/30 23:30:09 by lyubov           ###   ########.fr       */
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
# include <signal.h>
# include <semaphore.h>

//we have only philo struct that will be divided between processes
typedef struct s_philo
{
	int				n_phl;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				a_phl;
	int				eat_num;
	int				fed_ph;
	int				*id_arr;
	long			t_strt;
	struct timeval	t_tbl;
	sem_t			*sem_f;
	sem_t			*sem_p;
	sem_t			*sem_d;
	pthread_t		*t_arr;
}		t_philo;


//main


//valid
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_philo *philo);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);

//utils
void	ft_semcloser(t_philo *philo);
int		cleaner(char *pr_name, t_philo *philo);

//activ
void	*philo_monitor();
#endif
