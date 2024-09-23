/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:54:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 21:13:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

static void	t_mlx_circle_disk_update_err(t_mlx_coords *xy, int *err)
{
	if (*err <= 0)
	{
		xy->y += 1;
		*err += 2 * xy->y + 1;
	}
	if (*err > 0)
	{
		xy->x -= 1;
		*err -= 2 * xy->x + 1;
	}
}

static void	t_mlx_circle_disk_init_vars(t_mlx_coords *xy, int *err, int radius)
{
	xy->x = radius;
	xy->y = 0;
	*err = 0;
}

static void	update_temp(t_mlx_coords *temp, int x, int y)
{
	temp->x = x;
	temp->y = y;
}

void	t_mlx_draw_circle(t_image *img, t_mlx_coords *coords, int radius, unsigned int color)
{
	t_mlx_coords	xy;
	int				err;
	t_mlx_coords	temp;

	t_mlx_circle_disk_init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		update_temp(&temp, coords->x + xy.x, coords->y + xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.y, coords->y + xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.y, coords->y + xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.x, coords->y + xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.x, coords->y - xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.y, coords->y - xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.y, coords->y - xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.x, coords->y - xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		t_mlx_circle_disk_update_err(&xy, &err);
	}
}

void	t_mlx_draw_disk(t_image *img, t_mlx_coords *coords, int radius, unsigned int color)
{
	int				err;
	t_mlx_coords	xy;
	t_mlx_coords	temp;

	t_mlx_circle_disk_init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		temp.x = coords->x - xy.x - 1;
		while (++temp.x <= coords->x + xy.x)
		{
			temp.y = coords->y + xy.y;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.y;
			t_mlx_draw_pixel(img, &temp, color);
		}
		temp.x = coords->x - xy.y - 1;
		while (++temp.x <= coords->x + xy.y)
		{
			temp.y = coords->y + xy.x;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.x;
			t_mlx_draw_pixel(img, &temp, color);
		}
		t_mlx_circle_disk_update_err(&xy, &err);
	}
}
