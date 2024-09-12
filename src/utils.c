/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:47:19 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 11:52:53 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int						i;
	unsigned long long		res;

	i = 0;
	res = 0;
	if (ft_isdigit(str) == 1)
		ft_exit("Mets que des chiffres connard\n");
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res > 2147483647)
		ft_exit("Ton nombre est trop grand mashallah\n");
	return (res);
}

void	ft_exit(char *str)
{
	printf("%s", str);
	exit (ERROR);
}

long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}
