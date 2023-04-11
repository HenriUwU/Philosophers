/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:27:30 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/11 17:29:22 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("\033[0;33m");
	printf("[%li] [%i] has taken a fork 🥢\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_lock(philo->right_fork);
	printf("[%li] [%i] has taken a fork 🥢\n",
		get_timestamp(philo->data->start), philo->philo_id);
	printf("\033[0;34m");
	printf("[%li] [%i] is eating 🍜\n",
		get_timestamp(philo->data->start), philo->philo_id);
	printf("\033[0m");
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->nb_meals_mutex);
	philo->nb_meals_eaten++;
	pthread_mutex_unlock(&philo->nb_meals_mutex);
}
