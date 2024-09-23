/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:34:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:14:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s) - start;
	if (slen > len)
		slen = len;
	if (start >= ft_strlen(s))
		slen = 0;
	str = malloc(sizeof(char) * slen + 1);
	if (!str)
		return (0);
	i = 0;
	while (i != slen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
