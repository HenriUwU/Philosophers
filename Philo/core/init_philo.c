/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:13:59 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/19 13:39:28 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *data, int nb_philo)
{
	int	mutex_check;

	mutex_check = 0;
	while (nb_philo > 0)
	{
		nb_philo--;
		mutex_check = pthread_mutex_init(&data->forks[nb_philo].fork_mutex, \
				NULL);
		if (mutex_check != 0)
			return (-1);
	}
	mutex_check = pthread_mutex_init(&data->printf_mutex, NULL);
	if (mutex_check != 0)
		return (-1);
	mutex_check = pthread_mutex_init(&data->is_dead_mutex, NULL);
	if (mutex_check != 0)
		return (-1);
	mutex_check = pthread_mutex_init(&data->philo_satiated_mutex, NULL);
	if (mutex_check != 0)
		return (-1);
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		philo[i].nb_meals_eaten = 0;
		philo[i].left_fork = &data->forks[i];
		if (philo[i].philo_id == data->nb_philo)
			philo[i].right_fork = &data->forks[0];
		else
			philo[i].right_fork = &data->forks[i + 1];
		i++;
	}
	return (0);
}
