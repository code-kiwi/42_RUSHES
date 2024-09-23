/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:09:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 11:05:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_mem.h"

static void	extract_number_base(char *res, size_t len_res, long nb, char *base)
{
	unsigned long	num;
	size_t			i;
	size_t			len_base;

	if (nb < 0)
		num = (unsigned long) -1 * nb;
	else
		num = (unsigned long) nb;
	len_base = ft_strlen(base);
	i = len_res - 1;
	while (num > 0)
	{
		res[i] = base[num % len_base];
		i--;
		num /= len_base;
	}
	if (nb < 0)
		res[0] = '-';
}

char	*ft_ltoa_base(long nb, char *base)
{
	char	*res;
	size_t	len_base;
	size_t	len_res;

	if (base == NULL || !ft_is_valid_base(base))
		return (NULL);
	if (nb == 0)
		return (ft_ctoa(base[0]));
	len_base = ft_strlen(base);
	len_res = ft_get_long_len(nb, len_base);
	res = (char *) ft_calloc(len_res + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	extract_number_base(res, len_res, nb, base);
	return (res);
}

char	*ft_prepend_chars(char *str, char c, size_t len_total)
{
	char	*res;
	size_t	len_str;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	if (len_str >= len_total)
		return (ft_strdup(str));
	res = ft_calloc(len_total + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memset(res, c, len_total - len_str);
	ft_strlcat(res, str, len_total + 1);
	return (res);
}

char	*ft_append_chars(char *str, char c, size_t len_total)
{
	char	*res;
	size_t	len_str;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	if (len_str >= len_total)
		return (ft_strdup(str));
	res = ft_calloc(len_total + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str, len_total + 1);
	ft_memset(res + len_str, c, len_total - len_str);
	return (res);
}
