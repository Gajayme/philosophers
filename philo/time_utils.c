/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:09:15 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/29 00:28:50 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	count_time(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	timer(long start)
{
	long			passed;
	struct timeval	now;

	gettimeofday(&now, NULL);
	passed = (now.tv_sec * 1000 + now.tv_usec / 1000) - start;
	return (passed);
}

void	waiter(int time)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	usleep ((time * 95) / 100);
	gettimeofday(&now, NULL);
	while (((now.tv_sec * 1000 - start.tv_sec * 1000)
			+ (now.tv_usec / 1000 - start.tv_usec / 1000)) < time)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}