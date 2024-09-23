/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:55:33 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/02 00:44:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h" 

void	init_vector(t_vector *vector, size_t element_size)
{
	vector->element_size = element_size;
	vector->len = 0;
	vector->allocated = 0;
	vector->ptr = NULL;
}
