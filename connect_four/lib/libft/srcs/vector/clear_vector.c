/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:16:26 by lespenel          #+#    #+#             */
/*   Updated: 2023/12/02 03:20:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	clear_vector(t_vector *vector)
{
	if (vector->ptr)
		free(vector->ptr);
	vector->ptr = NULL;
	vector->len = 0;
	vector->allocated = 0;
	vector->element_size = 0;
}
