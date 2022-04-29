/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:14:56 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/29 20:54:10 by lyubov           ###   ########.fr       */
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
# include <semaphore.h>

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
	struct timeval	t_tbl;
	sem_t			*sem;
	pthread_t		*t_arr;
}		t_table;


//main


//valid
int		adder(char *arg, int flag, int *to_write);
int		valid(char **av, t_table *table);

//lib_utils
int		up_isdigit(char *arg);
long	up_atoi(const char *str);
int		up_putstr_fd(char *s, int fd);

#endif
