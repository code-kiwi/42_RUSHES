/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:23:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:23:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		cc;

	i = ft_strlen(s);
	cc = c;
	while (s[i] != cc && i != 0)
		i--;
	if (s[i] == cc)
		return ((char *)s + i);
	return (0);
}
