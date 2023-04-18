/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:21 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/18 17:34:12 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_philo_dead(t_philo *philo)
{
	long int	timestamp;

	if (philo->data->is_dead)
		return ;
	timestamp = get_timestamp(philo->data->start);
	if ((timestamp - philo->last_time_eaten) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->is_dead_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->is_dead_mutex);
		print_death(philo);
	}
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->data->nb_philo == 1)
	{
		printf("\033[0;33m[%li] [%d] has taken a fork 🥢\n",
			get_timestamp(philo->data->start), philo->philo_id);
		usleep(philo->data->time_to_die * 1000);
		print_death(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(20000);
	while (1)
	{
		is_philo_dead(philo);
		if (philo->data->is_dead)
			return (NULL);
		philo_eat(philo);
		philo_sleep(philo);
		if (philo->data->philo_satiated == philo->data->nb_philo)
			return (NULL);
	}
	return (NULL);
}

int	philo_thread(t_philo *philo, t_data *data)
{
	int	i;
	int	protection;

	i = 0;
	init_mutexes(data, philo, data->nb_philo);
	init_philo(philo, data);
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
