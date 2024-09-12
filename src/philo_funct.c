/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:36:12 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 12:13:57 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_checkdeath(long int timing, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->dead);
	timing = timestamp();
	if (data->death == 1)
	{
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	if (timing - philo->deathtime >= data->timetodie)
	{
		pthread_mutex_lock(&data->print);
		timing = timestamp();
		printf("%s[%ld] - Le philosophe numero %d "\
		"meurt\n", RED, timing - data->time, philo->index);
		pthread_mutex_unlock(&data->print);
		data->death += 1;
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

void	*thread_routine(void *ptr)
{
	t_data			*data;
	t_philo			*philo;
	long int		timing;
	pthread_mutex_t	timestamp_mutex;

	pthread_mutex_init(&timestamp_mutex, NULL);
	philo = (t_philo *)ptr;
	data = philo->data;
	timing = 0;
	philo->deathtime = timestamp();
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->status);
		philo->statusphilo = 4;
		pthread_mutex_unlock(&philo->status);
	}
	if (ft_while(philo, data, timestamp_mutex, timing) == 0)
		return (NULL);
	else
		return (NULL);
}

int	ft_while(t_philo *philo, t_data *data, \
pthread_mutex_t timestamp_mutex, long int timing)
{
	while (philo->nbmusteat)
	{
		if (ft_checkdeath(timing, data, philo) == 1)
			return (1);
		ft_think(timing, data, philo);
		if (ft_checkdeath(timing, data, philo) == 1)
			return (1);
		ft_takeownfork(timing, data, philo);
		if (ft_checkdeath(timing, data, philo) == 1)
			return (1);
		ft_takerightfork(timing, data, philo);
		if (ft_checkdeath(timing, data, philo) == 1)
			return (1);
		ft_eat(timing, data, philo, timestamp_mutex);
		if (ft_checkdeath(timing, data, philo) == 1)
			return (1);
		ft_sleep(timing, data, philo, timestamp_mutex);
	}
	return (0);
}

void	ft_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbphilo)
	{
		pthread_create(&data->philo->tid, NULL, thread_routine, data->philo);
		data->philo = data->philo->next;
		i++;
	}
	i = 0;
	while (i < data->nbphilo)
	{
		pthread_join(data->philo->tid, NULL);
		data->philo = data->philo->next;
		i++;
	}
}
