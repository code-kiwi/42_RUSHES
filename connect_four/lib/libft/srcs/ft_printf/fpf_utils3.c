/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:09:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 11:09:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ascii.h"

size_t	ft_get_long_len(long num, size_t base_len)
{
	size_t			size;
	unsigned long	nb;

	size = 1;
	if (num < 0)
	{
		nb = (unsigned long) -1 * num;
		size++;
	}
	else
		nb = (unsigned long) num;
	while (nb / base_len > 0)
	{
		size++;
		nb /= base_len;
	}
	return (size);
}

size_t	ft_get_ulong_len(unsigned long nb, size_t base_len)
{
	size_t			size;

	size = 1;
	while (nb / base_len > 0)
	{
		size++;
		nb /= base_len;
	}
	return (size);
}

bool	ft_is_valid_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (false);
	i = 0;
	while (i < base_len)
	{
		if (
			!ft_isprint(base[i]) || ft_isspace(base[i])
			|| base[i] == '+' || base[i] == '-'
		)
			return (false);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_isspace(int c)
{
	return (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	);
}
