/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:50:47 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 00:50:53 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	cc = c;
	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s)[i] != cc && i < n - 1)
		i++;
	if (((unsigned char *)s)[i] == cc)
		return ((void *)s + i);
	return (0);
}
