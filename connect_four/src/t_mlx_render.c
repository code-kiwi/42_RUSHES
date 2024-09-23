/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 19:45:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "connect.h"

bool	t_mlx_render(t_mlx *ui)
{
	if (ui == NULL || ui->img_buff == NULL)
		return (false);
	mlx_put_image_to_window(ui->mlx_ptr, ui->mlx_win, ui->img_buff->ptr, 0, 0);
	if (ui->img_buff == ui->img1)
		ui->img_buff = ui->img2;
	else
		ui->img_buff = ui->img1;
	return (true);
}
