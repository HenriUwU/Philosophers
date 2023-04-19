/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:27:30 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/19 13:54:20 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_fork(t_philo *philo)
{
	if (!philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("\033[0;33m[%li] [%i] has taken a fork 🥢\n",
			get_timestamp(philo->data->start), philo->philo_id);
		pthread_mutex_unlock(&philo->data->printf_mutex);
	}
}

static void	take_forks(t_philo *philo)
{
	while (philo->nb_forks < 2)
	{
		if (philo_dead(philo))
			break ;
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

static void	eat(t_philo *philo)
{
	long int	started_to_eat;

	if (philo_dead(philo))
		return ;
	started_to_eat = get_timestamp(philo->data->start);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("\033[0;34m[%li] [%i] is eating 🍜\n",
		get_timestamp(philo->data->start), philo->philo_id);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	philo->nb_forks = 0;
	philo->nb_meals_eaten++;
	while ((get_timestamp(philo->data->start) - started_to_eat)
		< philo->data->time_to_eat)
	{
		if (philo_dead(philo))
			return ;
		usleep(500);
	}
}

void	philo_eat(t_philo *philo)
{
	if (philo_dead(philo))
		return ;
	take_forks(philo);
	if (philo->nb_forks == 2)
		eat(philo);
	if (philo->nb_meals_eaten == philo->data->times_philo_must_eat)
	{
		pthread_mutex_lock(&philo->data->philo_satiated_mutex);
		philo->data->philo_satiated++;
		pthread_mutex_unlock(&philo->data->philo_satiated_mutex);
	}
	philo->last_time_eaten = get_timestamp(philo->data->start);
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	philo->left_fork->mutex_id = 0;
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->right_fork->mutex_id = 0;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}
