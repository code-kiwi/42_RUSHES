/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:02:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 03:15:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "ft_string.h"

static long int	ft_atol(const char *nptr, int *result);

int	ft_atoi_strict(const char	*nptr, int *result)
{
	return (ft_atol(nptr, result));
}

static long int	ft_atol(const char *nptr, int *result)
{
	long int	nb;
	size_t		index;

	index = 0;
	nb = 0;
	*result = 0;
	while ((*nptr <= 13 && *nptr >= 9) || *nptr == 32)
		nptr++;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		nb = nb * 10 + (nptr[index] - '0');
		if (nb < 0)
			return (-1);
		index++;
	}
	if (ft_strlen(nptr + index) && *(nptr + index) != '\n')
		return (-1);
	*result = nb;
	if (nptr[0] == '-')
		*result *= -1;
	return (0);
}
