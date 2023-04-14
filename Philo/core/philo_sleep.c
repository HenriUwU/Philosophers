/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:44:13 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/14 16:15:50 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->printf_mutex);
	printf("\033[0;35m[%li] [%d] is sleeping 😴\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->printf_mutex);
	usleep(philo->data->time_to_sleep);
	pthread_mutex_lock(&philo->printf_mutex);
	printf("\033[0;30m[%li] [%d] is thinking 🤔\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->printf_mutex);
}
