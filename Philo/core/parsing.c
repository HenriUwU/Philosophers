/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:57:43 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/10 11:39:20 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc >= 7)
	{
		write(2, "Error: invalid number of arguments\n", 36);
		return (-1);
	}
	data->times_philo_must_eat = 1;
	data->ac = argc;
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	if (args_check(data) == -1)
		return (-1);
	return (0);
}

int	args_check(t_data *data)
{
	if (data->nb_philo <= 0)
	{
		write(2, "Error: invalid number of philosophers\n", 38);
		return (-1);
	}
	if (data->time_to_die <= 0)
	{
		write(2, "Error: invalid time to die\n", 27);
		return (-1);
	}
	if (data->time_to_eat <= 0)
	{
		write(2, "Error: invalid time to eat\n", 27);
		return (-1);
	}
	if (data->time_to_sleep <= 0)
	{
		write(2, "Error invalid time to sleep\n", 29);
		return (-1);
	}
	if (data->times_philo_must_eat <= 0)
		write(2, "Error: invalid number of times each philosopher eat\n", 57);
	if (data->times_philo_must_eat <= 0)
		return (-1);
	return (0);
}
