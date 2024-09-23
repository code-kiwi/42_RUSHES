/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:21:56 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/08 16:51:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "connect.h"

void	t_mlx_destroy(t_mlx *ui)
{
	if (ui == NULL)
		return ;
	if (ui->mlx_ptr != NULL && ui->mlx_win != NULL)
		mlx_destroy_window(ui->mlx_ptr, ui->mlx_win);
	if (ui->mlx_ptr != NULL && ui->img1 != NULL)
		t_image_destroy(ui->mlx_ptr, ui->img1, true);
	if (ui->mlx_ptr != NULL && ui->img2 != NULL)
		t_image_destroy(ui->mlx_ptr, ui->img2, true);
	if (ui->mlx_ptr != NULL)
	{
		mlx_destroy_display(ui->mlx_ptr);
		free(ui->mlx_ptr);
		ui->mlx_ptr = NULL;
	}
	free(ui->title);
}