/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:59:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/06 05:51:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include <stdlib.h>

static	int	is_charset(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;

	if (!*set)
		return (ft_strdup(s1));
	while (is_charset(*s1, set))
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	len = ft_strlen(s1) - 1;
	while (is_charset(s1[len], set))
		len--;
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len + 1);
	str[len + 1] = '\0';
	return (str);
}

static	int	is_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
