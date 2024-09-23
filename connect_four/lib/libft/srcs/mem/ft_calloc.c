/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:53:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/06 05:54:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	sizee;

	sizee = nmemb * size;
	if (size != 0)
		if (sizee / size != nmemb)
			return (NULL);
	ptr = malloc(sizeof(char) * sizee);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizee);
	return (ptr);
}
