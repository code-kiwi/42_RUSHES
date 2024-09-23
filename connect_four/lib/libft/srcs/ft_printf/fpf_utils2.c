/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:09:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 11:08:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_mem.h"
#include "ascii.h"

unsigned long	ft_atoul(const char *nb_ptr)
{
	unsigned long	res;

	if (nb_ptr == NULL)
		return (0);
	res = 0;
	while (ft_isspace(*nb_ptr))
		nb_ptr++;
	if (*nb_ptr == '+')
		nb_ptr++;
	while (ft_isdigit(*nb_ptr))
	{
		res = res * 10 + ((unsigned long)(*nb_ptr - '0'));
		nb_ptr++;
	}
	return (res);
}

char	*ft_ltoa(long nb)
{
	return (ft_ltoa_base(nb, "0123456789"));
}

char	*ft_itoa(int n)
{
	return (ft_ltoa_base(n, "0123456789"));
}

char	*ft_ctoa(int c)
{
	char	*res;

	res = (char *) ft_calloc(2, sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = c;
	return (res);
}

char	*ft_ultoa_base(unsigned long nb, char *base)
{
	char	*res;
	size_t	len_base;
	size_t	len_res;
	size_t	i;

	if (base == NULL || !ft_is_valid_base(base))
		return (NULL);
	if (nb == 0)
		return (ft_ctoa(base[0]));
	len_base = ft_strlen(base);
	len_res = ft_get_ulong_len(nb, len_base);
	res = (char *) ft_calloc(len_res + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = len_res - 1;
	while (nb > 0)
	{
		res[i] = base[nb % len_base];
		i--;
		nb /= len_base;
	}
	return (res);
}
