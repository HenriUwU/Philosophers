/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:57:43 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/07 15:24:13 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(t_main *philo)
{
	if (philo->number_of_philosophers <= 0)
	{
		write(2, "Error: invalid number of philosophers\n", 38);
		return (-1);
	}
	if (philo->time_to_die <= 0)
	{
		write(2, "Error: invalid time to die\n", 27);
		return (-1);
	}
	if (philo->time_to_eat <= 0)
	{
		write(2, "Error: invalid time to eat\n", 27);
		return (-1);
	}
	if (philo->time_to_sleep <= 0)
	{
		write(2, "Error invalid time to sleep\n", 29);
		return (-1);
	}
	if (philo->number_of_times_each_philosopher_must_eat <= 0)
		write(2, "Error: invalid number of times each philosopher eat\n", 57);
	if (philo->number_of_times_each_philosopher_must_eat <= 0)
		return (-1);
	return (0);
}
