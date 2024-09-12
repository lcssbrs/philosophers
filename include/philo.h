/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:16:28 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 12:18:13 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define BLACK  "\e[1;30m"
# define RED  "\e[0;31m"
# define GREEN  "\e[1;92m"
# define YELLOW  "\e[1;33m"
# define BLUE  "\e[0;36m"
# define PURPLE  "\e[1;35m"
# define CYAN  "\e[0;36m"
# define WHITE  "\e[1;97m"
# define ERROR -1
# define WAIT 1000

typedef struct s_philo
{
	int				index;
	int				statusphilo;
	int				statusfork;
	int				nbmusteat;
	long int		deathtime;
	pthread_mutex_t	fork;
	pthread_mutex_t	status;
	pthread_t		tid;
	struct s_data	*data;
	struct s_philo	*next;
}	t_philo;

typedef struct s_data
{
	int				nbphilo;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				nbmusteat;
	int				death;
	pthread_mutex_t	dead;
	long int		time;
	pthread_mutex_t	print;
	struct s_philo	*philo;
}	t_data;

//check_args.c
void		ft_check_ac(int ac, char **ag);

//init.c
t_philo		*ft_init_philo(int size, t_data *data);
t_data		*ft_init_data(int ac, char **ag);

//utils.c
int			ft_isdigit(char *str);
int			ft_atoi(char *str);
void		ft_exit(char *str);
long int	timestamp(void);

//utils_philo.c
void		ft_free(t_data *data);
void		ft_free_philo(t_philo *philo);
void		ft_usleep(int time, pthread_mutex_t timestamp_mutex);

//philo_move.c
void		ft_sleep(long int timing, t_data *data, t_philo *philo, \
pthread_mutex_t timestamp_mutex);
void		ft_eat(long int timing, t_data *data, t_philo *philo, \
pthread_mutex_t timestamp_mutex);
void		ft_takerightfork(long int timing, t_data *data, t_philo *philo);
void		ft_takeownfork(long int timing, t_data *data, t_philo *philo);
void		ft_think(long int timing, t_data *data, t_philo *philo);

//philo_funct
void		ft_process(t_data *data);

int			ft_while(t_philo *philo, t_data *data, \
pthread_mutex_t timestamp_mutex, long int timing);

#endif
