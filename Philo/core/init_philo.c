/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:13:59 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/10 17:21:33 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->philo_id % 2 == 0)
		usleep(20000);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("Philosopher %d,")

	}
	printf("philo : %d\n", philo->philo_id);
	return (NULL);
}

int	init_fork(t_fork *forks, int nb_philo)
{
	int	mutex_check;

	mutex_check = 0;
	while (nb_philo > 0)
	{
		mutex_check = pthread_mutex_init(&forks->forks[nb_philo], NULL);
		if (mutex_check != 0)
			return (-1);
		nb_philo--;
	}
	return (0);
}

int	init_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	philo->philo_id = 0;
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
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, ft_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}
