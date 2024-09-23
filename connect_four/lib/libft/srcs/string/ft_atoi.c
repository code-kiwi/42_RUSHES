/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:21:09 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:21:11 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static	long int	ft_atol(const char *nptr);

int	ft_atoi(const char	*nptr)
{
	return (ft_atol(nptr));
}

static long int	ft_atol(const char *nptr)
{
	long int	nb;
	size_t		index;

	index = 0;
	nb = 0;
	while ((*nptr <= 13 && *nptr >= 9) || *nptr == 32)
		nptr++;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		nb = nb * 10 + (nptr[index] - '0');
		if (nb < 0)
		{
			if (nptr[0] == '-')
				return (LONG_MIN);
			return (LONG_MAX);
		}
		index++;
	}
	if (nptr[0] == '-')
		return (nb * -1);
	return (nb);
}
