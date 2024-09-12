/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:11:17 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 11:50:25 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **ag)
{
	t_data	*data;

	ft_check_ac(ac, ag);
	data = ft_init_data(ac, ag);
	ft_process(data);
	ft_free(data);
}
