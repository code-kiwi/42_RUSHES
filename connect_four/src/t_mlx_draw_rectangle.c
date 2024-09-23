/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:54:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 21:13:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

void	t_mlx_draw_rect(t_image *img, t_mlx_coords *pos, t_mlx_coords *size, unsigned int color)
{
	int				i;
	int				j;
	unsigned int	*img_addr;

	if (img == NULL || pos == NULL || size == NULL)
		return ;
	img_addr = (unsigned int *) img->addr;
	i = 0;
	while (i < size->y && i + pos->y < img->height)
	{
		j = 0;
		while (j < size->x && j + pos->x < img->width)
		{
			*(img_addr + (i + pos->y) * img->width + j + pos->x) = color;
			j++;
		}
		i++;
	}
}
