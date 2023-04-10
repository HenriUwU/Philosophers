/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:35:27 by hsebille          #+#    #+#             */
/*   Updated: 2023/04/10 15:38:23 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;

	if (nmemb * size > INT_MAX || nmemb > INT_MAX || size > INT_MAX)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == (NULL))
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
