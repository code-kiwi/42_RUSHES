/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:23:07 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:23:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i != len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j]
			&& (i + j) != len)
		{
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *)big + i);
		else
			i++;
	}
	return (0);
}
