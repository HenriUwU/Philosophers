/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:44:13 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/18 17:21:40 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	long int	started_to_sleep;

	started_to_sleep = get_timestamp(philo->data->start);
	if (philo->data->is_dead)
		return ;
	pthread_mutex_lock(&philo->printf_mutex);
	printf("\033[0;35m[%li] [%d] is sleeping 😴\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->printf_mutex);
	while ((get_timestamp(philo->data->start) - started_to_sleep)
		< philo->data->time_to_sleep)
	{
		is_philo_dead(philo);
		if (philo->data->is_dead)
			return ;
		usleep(500);
	}
	if (!philo->data->is_dead)
	{
		pthread_mutex_lock(&philo->printf_mutex);
		printf("\033[0;36m[%li] [%d] is thinking 🤔\n",
			get_timestamp(philo->data->start), philo->philo_id);
		pthread_mutex_unlock(&philo->printf_mutex);
	}
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->printf_mutex);
	printf("\033[0;31m[%li] [%d] died 🪦\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->printf_mutex);
}
