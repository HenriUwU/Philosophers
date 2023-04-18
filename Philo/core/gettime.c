/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:49:23 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/18 15:30:03 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime(void)
{
	struct timeval	tv;
	long int		time;
	int				check;

	check = gettimeofday(&tv, NULL);
	if (check == -1)
		return (-1);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long int	get_timestamp(long int start)
{
	long int	timestamp;

	timestamp = gettime() - start;
	return (timestamp);
}
