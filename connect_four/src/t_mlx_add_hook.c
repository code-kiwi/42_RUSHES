/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_add_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:40:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/08 15:21:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "connect.h"

bool	t_mlx_add_hook(
	t_mlx *ui,
	int (*handler)(),
	void *data,
	enum e_hook_type hook_type
)
{
	if (ui == NULL || handler == NULL)
		return (false);
	if (hook_type == HOOK_DESTROY)
		mlx_hook(ui->mlx_win, MLX_ON_DESTROY, (1L << 3), handler, data);
	else if (hook_type == HOOK_KEY_RELEASE)
		mlx_hook(ui->mlx_win, MLX_ON_KEYRELEASE, (1L << 1), handler, data);
	else if (hook_type == HOOK_KEY_PRESS)
		mlx_hook(ui->mlx_win, MLX_ON_KEYPRESS, (1L << 0), handler, data);
	else if (hook_type == HOOK_MOUSE_MOVE)
		mlx_hook(ui->mlx_win, MLX_ON_MOUSEMOVE, (1L << 6), handler, data);
	else if (hook_type == HOOK_MOUSE_PRESS)
		mlx_hook(ui->mlx_win, MLX_ON_MOUSEDOWN, (1L << 2), handler, data);
	else if (hook_type == HOOK_MOUSE_RELEASE)
		mlx_hook(ui->mlx_win, MLX_ON_MOUSEUP, (1L << 3), handler, data);
	else if (hook_type == HOOK_LOOP)
		mlx_loop_hook(ui->mlx_ptr, handler, data);
	else
		return (false);
	return (true);
}
