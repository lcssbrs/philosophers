/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:01:13 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 12:07:55 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_sleep(long int timing, t_data *data, t_philo *philo, \
pthread_mutex_t timestamp_mutex)
{
	if (philo->statusphilo == 4)
	{
		pthread_mutex_lock(&data->print);
		timing = timestamp();
		printf("%s[%ld] - Le philosophe numero %d dort\n", \
		YELLOW, timing - data->time, philo->index);
		pthread_mutex_unlock(&data->print);
		ft_usleep(data->timetosleep, timestamp_mutex);
		philo->statusphilo = 0;
	}
}

void	ft_eat(long int timing, t_data *data, t_philo *philo, \
pthread_mutex_t timestamp_mutex)
{
	pthread_mutex_lock(&philo->status);
	if (philo->statusphilo == 3)
	{
		pthread_mutex_lock(&data->print);
		timing = timestamp();
		printf("%s[%ld] - Le philosophe numero %d mange %d fois\n", \
		GREEN, timing - data->time, philo->index, \
		data->nbmusteat - philo->nbmusteat + 1);
		philo->deathtime = timing;
		pthread_mutex_unlock(&data->print);
		philo->nbmusteat -= 1;
		ft_usleep(data->timetoeat, timestamp_mutex);
		pthread_mutex_lock(&philo->fork);
		philo->statusfork = 0;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_lock(&philo->next->fork);
		philo->next->statusfork = 0;
		pthread_mutex_unlock(&philo->next->fork);
		philo->statusphilo += 1;
	}
	pthread_mutex_unlock(&philo->status);
}

void	ft_takerightfork(long int timing, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->status);
	if (philo->statusphilo > 0 && philo->statusphilo < 3)
	{
		pthread_mutex_lock(&philo->next->fork);
		if (philo->next->statusfork == 0)
		{
			philo->next->statusfork = 1;
			philo->statusphilo += 1;
			pthread_mutex_lock(&data->print);
			timing = timestamp();
			printf("%s[%ld] - Le philosophe numero %d "\
			"prend la fourchette de droite\n", \
			PURPLE, timing - data->time, philo->index);
			pthread_mutex_unlock(&data->print);
		}
		pthread_mutex_unlock(&philo->next->fork);
	}
	pthread_mutex_unlock(&philo->status);
}

void	ft_takeownfork(long int timing, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->status);
	if (philo->statusphilo > 0 && philo->statusphilo < 3)
	{
		pthread_mutex_lock(&philo->fork);
		if (philo->statusfork == 0)
		{
			philo->statusfork = 1;
			philo->statusphilo += 1;
			pthread_mutex_lock(&data->print);
			timing = timestamp();
			printf("%s[%ld] - Le philosophe numero %d "\
			"prend sa propre fourchette\n", \
			BLUE, timing - data->time, philo->index);
			pthread_mutex_unlock(&data->print);
		}
		pthread_mutex_unlock(&philo->fork);
	}
	pthread_mutex_unlock(&philo->status);
}

void	ft_think(long int timing, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->status);
	if (philo->statusphilo == 0)
	{
		pthread_mutex_lock(&data->print);
		timing = timestamp();
		printf("%s[%ld] - Le philosophe numero %d pense\n", \
		WHITE, timing - data->time, philo->index);
		pthread_mutex_unlock(&data->print);
		philo->statusphilo += 1;
	}
	pthread_mutex_unlock(&philo->status);
}
