/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:31:06 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/10 16:27:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_data			data;
	pthread_mutex_t	*forks;
	int				parsing_check;

	(void)philo;
	parsing_check = parsing(&data, argc, argv);
	if (parsing_check == -1)
		return (1);
	philo = ft_calloc(sizeof(t_philo), data.nb_philo);
	forks = ft_calloc(sizeof(pthread_mutex_t), data.nb_philo);
	if (philo == NULL || forks == NULL)
		return (1);
	init_philo(philo, &data, forks);
	return (0);
}
