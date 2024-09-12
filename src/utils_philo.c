/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:55:23 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 12:00:08 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(int time, pthread_mutex_t timestamp_mutex)
{
	long long int	value;

	pthread_mutex_lock(&timestamp_mutex);
	value = timestamp();
	pthread_mutex_unlock(&timestamp_mutex);
	while (timestamp() - value < time)
	{
		usleep(1000);
	}
}

void	ft_free_philo(t_philo *philo)
{
	int		i;
	int		philos;
	t_philo	*tmp;

	i = 0;
	philos = philo->data->nbphilo;
	while (i < philos)
	{
		tmp = philo->next;
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->status);
		free(philo);
		philo = tmp;
		i++;
	}
}

void	ft_free(t_data *data)
{
	ft_free_philo(data->philo);
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->print);
	free(data);
}
