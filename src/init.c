/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:17:41 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 11:53:31 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_init_philo(int size, t_data *data)
{
	t_philo		*philo;
	t_philo		*tmp;
	int			index;

	index = 0;
	philo = malloc(sizeof(t_philo));
	tmp = philo;
	while (++index <= size)
	{
		philo->index = index;
		philo->statusphilo = 0;
		philo->statusfork = 0;
		philo->deathtime = 0;
		philo->nbmusteat = data->nbmusteat;
		philo->data = data;
		pthread_mutex_init(&philo->fork, NULL);
		pthread_mutex_init(&philo->status, NULL);
		if (index + 1 <= size)
		{
			philo->next = malloc(sizeof(t_philo));
			philo = philo->next;
		}
	}
	philo->next = tmp;
	return (tmp);
}

t_data	*ft_init_data(int ac, char **ag)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->nbphilo = ft_atoi(ag[1]);
	data->timetodie = ft_atoi(ag[2]);
	data->timetoeat = ft_atoi(ag[3]);
	data->timetosleep = ft_atoi(ag[4]);
	data->time = timestamp();
	data->death = 0;
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	if (ac == 6)
		data->nbmusteat = ft_atoi(ag[5]);
	else
		data->nbmusteat = -1;
	data->philo = ft_init_philo(data->nbphilo, data);
	return (data);
}
