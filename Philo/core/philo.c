/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:21 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/19 14:07:11 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("\033[0;31m[%li] [%d] died 🪦\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

static void	special_print(t_philo *philo)
{
	printf("\033[0;33m[%li] [%d] has taken a fork 🥢\n",
		get_timestamp(philo->data->start), philo->philo_id);
	usleep(philo->data->time_to_die * 1000);
	print_death(philo);
}

static void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->data->nb_philo == 1)
	{
		special_print(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(20000);
	while (1)
	{
		if (philo_dead(philo))
			return (NULL);
		philo_eat(philo);
		philo_sleep(philo);
		pthread_mutex_lock(&philo->data->philo_satiated_mutex);
		if (philo->data->philo_satiated == philo->data->nb_philo)
		{
			pthread_mutex_unlock(&philo->data->philo_satiated_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->philo_satiated_mutex);
	}
	return (NULL);
}

int	philo_dead(t_philo *philo)
{
	long int	timestamp;

	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	timestamp = get_timestamp(philo->data->start);
	if ((timestamp - philo->last_time_eaten) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		print_death(philo);
		return (1);
	}
	return (0);
}

int	philo_thread(t_philo *philo, t_data *data)
{
	int	i;
	int	protection;

	i = 0;
	if (init_mutexes(data, data->nb_philo) == -1)
		return (-1);
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
