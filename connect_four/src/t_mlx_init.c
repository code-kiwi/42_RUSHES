/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:27:05 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/08 16:51:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "connect.h"
#include "ft_mem.h"
#include "ft_string.h"

static bool	t_mlx_init_images(t_mlx *ui, int img_width, int img_height)
{
	if (ui == NULL || ui->mlx_ptr == NULL || img_width < 0 || img_height < 0)
		return (false);
	ui->img1 = t_image_init(ui->mlx_ptr, img_width, img_height);
	if (ui->img1 == NULL)
		return (false);
	ui->img2 = t_image_init(ui->mlx_ptr, img_width, img_height);
	if (ui->img2 == NULL)
	{
		t_image_destroy(ui->mlx_ptr, ui->img1, true);
		ui->img1 = NULL;
		return (false);
	}
	ui->img_buff = ui->img2;
	return (true);
}

bool	t_mlx_init(t_board *board, t_mlx *ui)
{
	if (board == NULL || ui == NULL)
		return (false);
	ft_memset(ui, 0, sizeof(t_mlx));
	ui->mlx_ptr = mlx_init();
	if (ui->mlx_ptr == NULL)
		return (false);
	if (!t_mlx_init_images(ui, UI_WIDTH, UI_HEIGHT))
	{
		t_mlx_destroy(ui);
		return (false);
	}
	ui->width = UI_WIDTH;
	ui->width_half = UI_WIDTH / 2;
	ui->height = UI_HEIGHT;
	ui->height_half = UI_HEIGHT / 2;
	ui->title = ft_strdup(UI_TITLE);
	if (ui->title == NULL)
	{
		t_mlx_destroy(ui);
		return (false);
	}
	return (true);
}

bool	t_mlx_launch(t_mlx *ui)
{
	if (ui == NULL || ui->mlx_ptr == NULL)
		return (false);
	ui->mlx_win = mlx_new_window(ui->mlx_ptr, ui->width, ui->height, ui->title);
	if (ui->mlx_win != NULL)
		t_mlx_center_cursor(ui);
	return (ui->mlx_win != NULL);
}
