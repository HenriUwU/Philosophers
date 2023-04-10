/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:35:33 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/10 11:05:07 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/philo.h"

static int	ft_overflow(long nb)
{
	if (nb > 2147483647)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;

	if (nptr == NULL)
		return (-1);
	i = 0;
	nb = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
		return (-1);
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-1);
		nb = nb * 10 + nptr[i] - '0';
		i++;
		if (ft_overflow(nb) == -1)
			return (-1);
	}
	return (nb);
}
