/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 05:12:49 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/02 05:22:41 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	add_str_vector(t_vector *vector, void *new_content, size_t n)
{
	size_t	i;
	char	*zero;

	zero = NULL;
	i = 0;
	while (i != n)
	{
		if (add_vector(vector, new_content + i))
			return (1);
		i++;
	}
	if (add_vector(vector, &zero))
		return (1);
	return (0);
}
