/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_mouse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:32:11 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 19:32:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"
#include "mlx.h"

void	t_mlx_center_cursor(t_mlx *mlx)
{
	if (mlx == NULL || mlx->mlx_ptr == NULL || mlx->mlx_win == NULL)
		return ;
	mlx_mouse_move(mlx->mlx_ptr, mlx->mlx_win, mlx->width_half, mlx->height_half);
}