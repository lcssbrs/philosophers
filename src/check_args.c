/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:11:11 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/29 11:48:16 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_check_ac(int ac, char **ag)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		ft_exit("ERROR\nWRONG QUANTITY OF ARGS\n");
	else if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (ft_isdigit(ag[i]) == 1)
				ft_exit("ERROR\nWRONG TYPE OF ARGS");
			i++;
		}
	}
}
