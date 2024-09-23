/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:52:23 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/26 21:56:37 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct s_vector
{
	void	*ptr;
	size_t	len;
	size_t	allocated;
	size_t	element_size;
}			t_vector;

void	*at_vector(t_vector *vector, size_t index);
void	init_vector(t_vector *vector, size_t vector_size);
int		add_vector(t_vector *vector, void *new_content);
int		add_multiple_vector(t_vector *vector, void *new_content, size_t n);
int		remove_vector(t_vector *vector, size_t	content_index);
void	clear_vector(t_vector *vector);
int		add_str_vector(t_vector *vector, void *new_content, size_t n);

#endif
