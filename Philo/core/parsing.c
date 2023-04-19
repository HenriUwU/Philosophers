/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:57:43 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/19 13:26:10 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_check(char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
	{
		write(2, "Error: invalid number of philosophers\n", 38);
		return (-1);
	}
	if (ft_atoi(argv[2]) <= 0)
	{
		write(2, "Error: invalid time to die\n", 27);
		return (-1);
	}
	if (ft_atoi(argv[3]) <= 0)
	{
		write(2, "Error: invalid time to eat\n", 27);
		return (-1);
	}
	if (ft_atoi(argv[4]) <= 0)
	{
		write(2, "Error: invalid time to sleep\n", 29);
		return (-1);
	}
	return (0);
}

int	parsing(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc >= 7)
	{
		write(2, "Error: invalid number of arguments\n", 36);
		return (-1);
	}
	if (args_check(argv) == -1)
		return (-1);
	data->times_philo_must_eat = -1;
	data->philo_satiated = 0;
	data->is_dead = 0;
	data->start = gettime();
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			write(2, "Error: invalid number of times each philo must eat\n", 51);
			return (-1);
		}
		data->times_philo_must_eat = ft_atoi(argv[5]);
	}
	return (0);
}
