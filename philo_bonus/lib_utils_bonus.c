/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:28:21 by gajayme           #+#    #+#             */
/*   Updated: 2022/05/04 15:36:49 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	up_atoi(const char *str)
{
	long	res;
	int		negative;

	negative = 1;
	res = 0;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int	up_isdigit(char *arg)
{
	while (*arg)
	{
		if (*arg > 47 && *arg < 58)
			arg ++;
		else
			return (1);
	}
	return (0);
}

int	up_putstr_fd(char *s, int fd)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (write(fd, s, 1))
			s += 1;
	}
	return (0);
}

void	killing(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->a_phl)
		kill(philo->id_arr[i], SIGKILL);
}
