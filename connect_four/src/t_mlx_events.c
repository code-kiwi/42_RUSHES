/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:47:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/08 17:20:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "connect.h"
#include "mlx.h"

static int	destroy_handler(t_board *board)
{
	if (board == NULL)
		return (0);
	mlx_loop_end(board->ui.mlx_ptr);
	return (0);
}

static int	key_release_handler(int key, t_board *board)
{
	if (board == NULL)
		return (0);
	if (key == KEY_ESC)
		return destroy_handler(board);
	return (0);
}

static bool	is_mouse_over_grid(int x, int y, t_ui_grid_info *info)
{
	return (
		x > info->pos.x && x < info->grid_size.x
		&& y > info->pos.y && y < info->grid_size.y
	);
}

static int	get_hovered_column_index(int x, t_board *board, t_ui_grid_info *info)
{
	return (min_int(x / info->cell_size.x, board->width - 1));
}

static int	mouse_move_handler(int x, int y, t_board *board)
{
	t_ui_grid_info	*info;

	if (board == NULL || board->curr_player != J1 || board->status != PLAYING)
		return (0);
	info = &board->ui_grid_info;
	info->hovered_col = is_mouse_over_grid(x, y, info) ? get_hovered_column_index(x, board, info) : -1;
	return (0);
}

static int	mouse_press_handler(int button, int x, int y, t_board *board)
{
	t_ui_grid_info	*info;

	if (board == NULL || board->curr_player != J1 || board->status != PLAYING)
		return (0);
	info = &board->ui_grid_info;
	if (is_mouse_over_grid(x, y, info) && button == MOUSE_LEFT)
		info->selected_col = get_hovered_column_index(x, board, info);
	return (0);
}

bool	add_event_handlers(t_board *board)
{
	if (board == NULL)
		return (false);
	if (
		!t_mlx_add_hook(&board->ui, destroy_handler, board, HOOK_DESTROY)
		|| !t_mlx_add_hook(&board->ui, key_release_handler, board, HOOK_KEY_RELEASE)
		|| !t_mlx_add_hook(&board->ui, mouse_move_handler, board, HOOK_MOUSE_MOVE)
		|| !t_mlx_add_hook(&board->ui, mouse_press_handler, board, HOOK_MOUSE_PRESS)
		|| !t_mlx_add_hook(&board->ui, game_loop_ui, board, HOOK_LOOP)
	)
		return (false);
	return (true);
}
