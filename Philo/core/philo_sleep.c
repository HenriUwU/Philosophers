/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:44:13 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/19 14:14:24 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	long int	started_to_sleep;

	if (philo_dead(philo))
		return ;
	started_to_sleep = get_timestamp(philo->data->start);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("\033[0;35m[%li] [%d] is sleeping 😴\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	while ((get_timestamp(philo->data->start) - started_to_sleep)
		< philo->data->time_to_sleep)
	{
		if (philo_dead(philo))
			return ;
		usleep(500);
	}
	if (!philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("\033[0;36m[%li] [%d] is thinking 🤔\n",
			get_timestamp(philo->data->start), philo->philo_id);
		pthread_mutex_unlock(&philo->data->printf_mutex);
	}
}
