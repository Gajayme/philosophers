/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:28:21 by gajayme           #+#    #+#             */
/*   Updated: 2022/04/16 18:40:03 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (*arg > 47 || *arg < 58)
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

void	up_bzero(void *s, size_t n)
{
	char	*arr;

	arr = s;
	while (n --)
		*arr++ = '\0';
}

void	*up_calloc(size_t size, t_table *table, t_philo *philo)
{
	void	*p;

	p = malloc(size);
	if (!p)
		up_perror(NULL, "philo", table, philo);
	up_bzero(p, size);
	return (p);
}
