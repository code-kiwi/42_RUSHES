/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:54:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 21:13:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

static void	t_mlx_draw_line_init(t_mlx_coords *coords_start, t_mlx_coords *coords_end, t_mlx_coords *dxy, t_mlx_coords *sxy)
{
	dxy->x = abs(coords_end->x - coords_start->x);
	dxy->y = abs(coords_end->y - coords_start->y);
	sxy->x = -1;
	if (coords_start->x < coords_end->x)
		sxy->x = 1;
	sxy->y = -1;
	if (coords_start->y < coords_end->y)
		sxy->y = 1;
}

static bool	t_mlx_draw_line_is_done(t_mlx_coords *coords_curr, t_mlx_coords *coords_end, t_mlx_coords *sxy)
{
	return (
		(sxy->x == -1 && coords_curr->x < coords_end->x)
		|| (sxy->x == 1 && coords_curr->x > coords_end->x)
		|| (sxy->y == -1 && coords_curr->y < coords_end->y)
		|| (sxy->y == 1 && coords_curr->y > coords_end->y)
	);
}

void	t_mlx_draw_line(t_image *img, t_mlx_coords coords_start, t_mlx_coords coords_end, unsigned int color)
{
	t_mlx_coords	dxy;
	t_mlx_coords	sxy;
	int				err;

	t_mlx_draw_line_init(&coords_start, &coords_end, &dxy, &sxy);
	err = dxy.x - dxy.y;
	while (!t_mlx_draw_line_is_done(&coords_start, &coords_end, &sxy))
	{
		t_mlx_draw_pixel(img, &coords_start, color);
		if (coords_start.x == coords_end.x && coords_start.y == coords_end.y)
			break ;
		if (2 * err > -dxy.y)
		{
			err -= dxy.y;
			coords_start.x += sxy.x;
		}
		if (2 * err < dxy.x)
		{
			err += dxy.x;
			coords_start.y += sxy.y;
		}
	}
}
