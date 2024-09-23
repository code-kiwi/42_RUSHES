/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:54:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 21:13:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

void	t_mlx_draw_pixel(t_image *img, t_mlx_coords *coords, unsigned int color)
{
	*(unsigned int *)(img->addr + \
		(coords->y * img->line_len + (coords->x * img->bpp_factor))) = color;
}
