/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:21 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/11 17:18:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->philo_id % 2 == 0)
		usleep(20000);
	while (1)
	{
		philo_eat(philo);
	}
	return (NULL);
}

int	philo_thread(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;
	int	protection;

	i = 0;
	init_mutexes(forks, philo, data->nb_philo);
	init_philo(philo, data, forks);
	while (i < data->nb_philo)
	{
		protection = pthread_create(&philo[i].thread_id, NULL,
				routine, &philo[i]);
		if (protection != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		protection = pthread_join(philo[i].thread_id, NULL);
		if (protection != 0)
			return (-1);
		i++;
	}
	return (0);
}
