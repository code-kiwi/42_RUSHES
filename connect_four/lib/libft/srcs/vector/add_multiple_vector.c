/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_multiple_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:06:33 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/10 02:08:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	add_multiple_vector(t_vector *vector, void *new_content, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (add_vector(vector, new_content + i))
			return (1);
		i++;
	}
	return (0);
}
