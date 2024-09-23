/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:53:15 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 00:25:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*at_vector(t_vector *vector, size_t index)
{
	char	*element_address;

	element_address = (char *)vector->ptr + index * vector->element_size;
	return ((void *)element_address);
}
