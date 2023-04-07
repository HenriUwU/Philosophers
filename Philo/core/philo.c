/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:31:06 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/07 17:39:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	philo;

	if (ac < 5 || ac >= 7)
	{
		write(2, "Error: invalid number of arguments\n", 36);
		return (0);
	}
	philo.data->number_of_times_each_philosopher_must_eat = 0;
	philo.data->number_of_philosophers = ft_atoi(av[1]);
	philo.data->time_to_die = ft_atoi(av[2]);
	philo.data->time_to_eat = ft_atoi(av[3]);
	philo.data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo.data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	if (args_check(&philo) == -1)
		return (1);
	return (0);
}
