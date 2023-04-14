/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:27:30 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/14 17:14:04 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->printf_mutex);
	printf("\033[0;33m[%li] [%i] has taken a fork 🥢\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->printf_mutex);
}

void	take_forks(t_philo *philo)
{
	while (philo->nb_forks < 2)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if (philo->left_fork->mutex_id == 0)
		{
			philo->left_fork->mutex_id = 1;
			philo->nb_forks++;
			print_fork(philo);
		}
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if (philo->right_fork->mutex_id == 0)
		{
			philo->right_fork->mutex_id = 1;
			philo->nb_forks++;
			print_fork(philo);
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
}

void	eat(t_philo *philo)
{
	if (philo->nb_forks == 2)
	{
		pthread_mutex_lock(&philo->printf_mutex);
		printf("\033[0;34m[%li] [%i] is eating 🍜\n",
			get_timestamp(philo->data->start), philo->philo_id);
		pthread_mutex_unlock(&philo->printf_mutex);
		pthread_mutex_lock(&philo->nb_forks_mutex);
		philo->nb_forks = 0;
		pthread_mutex_unlock(&philo->nb_forks_mutex);
		usleep(philo->data->time_to_eat);
	}
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	eat(philo);
	pthread_mutex_lock(&philo->last_time_eaten_mutex);
	philo->last_time_eaten = get_timestamp(philo->data->start);
	pthread_mutex_unlock(&philo->last_time_eaten_mutex);
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	philo->left_fork->mutex_id = 0;
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->right_fork->mutex_id = 0;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}
