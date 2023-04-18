/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:31:06 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/18 17:34:41 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_data			data;
	int				check;

	(void)philo;
	check = parsing(&data, argc, argv);
	if (check == -1)
		return (1);
	philo = ft_calloc(sizeof(t_philo), data.nb_philo);
	data.forks = ft_calloc(sizeof(t_fork), data.nb_philo);
	if (philo == NULL || data.forks == NULL)
		return (1);
	check = philo_thread(philo, &data);
	if (check == -1)
		return (1);
	free(philo);
	free(data.forks);
	return (0);
}
