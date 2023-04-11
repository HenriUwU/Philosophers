/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:13:59 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/11 17:13:52 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(pthread_mutex_t *forks, t_philo *philo, int nb_philo)
{
	int	mutex_check;

	mutex_check = 0;
	while (nb_philo > 0)
	{
		nb_philo--;
		mutex_check = pthread_mutex_init(&forks[nb_philo], NULL);
		if (mutex_check != 0)
			return (-1);
	}
	mutex_check = pthread_mutex_init(&philo->nb_meals_mutex, NULL);
	if (mutex_check != 0)
		return (-1);
	return (0);
}

int	init_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		philo[i].nb_meals_eaten = 0;
		philo[i].left_fork = &forks[i];
		if (philo[i].philo_id == data->nb_philo)
			philo[i].right_fork = &forks[0];
		else
			philo[i].right_fork = &forks[i + 1];
		i++;
	}
	return (0);
}
