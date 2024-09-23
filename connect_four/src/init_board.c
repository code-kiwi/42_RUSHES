/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:05:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/08 20:50:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "connect.h"
#include "ft_mem.h"

static	int	init_coll_order(t_board *board);
static	int	set_depth(int width);

int	init_board(t_board *board, int height, int width, bool ui_enabled)
{
	int	i;

	ft_memset(board, 0, sizeof(t_board));
	board->width = width;
	board->width_in_char = get_width_in_char(board->width);
	board->height = height;
	board->nb_moves = 0;
	board->nb_slot = width * height;
	board->status = PLAYING;
	board->winner = 0;
	board->curr_player = rand() % 2 == 0 ? J1 : AI;
	board->ui_enabled = ui_enabled;
	board->board = ft_calloc(height, sizeof(char *));
	board->depth = set_depth(width);
	if (board->board == NULL)
		return (-1);
	i = 0;
	while (i < height)
	{
		board->board[i] = ft_calloc(width, sizeof(char));
		if (board->board[i] == NULL)
			return (-1);
		++i;
	}
	if (init_coll_order(board) == -1)
		return (-1);
	return (0);
}

int	get_width_in_char(int width)
{
	int	width_in_char;

	width_in_char = 0;
	while (width > 0)
	{
		width /= 10;
		width_in_char++;
	}
	return (width_in_char);
}

static	int	init_coll_order(t_board *board)
{
	int	center_coll = (board->width / 2);
	int left = center_coll - 1;
	int right = center_coll + 1;
	int	i;

	board->coll_order = ft_calloc(board->width, sizeof(int));
	if (board->coll_order == NULL)
		return (-1);

	board->coll_order[0] = center_coll;
	i = 1;
	while (left >= 0 || right < board->width)
	{
		if (left >= 0)
		{
			board->coll_order[i] = left;
			++i;
			--left;
		}
		if (right < board->width)
		{
			board->coll_order[i] = right;
			++i;
			++right;
		}
	}
	return (0);
}

static	int	set_depth(int width)
{
	if (width <= 7)
		return (15);
	if (width <= 10)
		return (12);
	if (width <= 20)
		return (8);
	if (width < 25)
		return (7);
	return (5);
}

void	init_ui_grid_info(t_board *board, t_ui_grid_info *info)
{
	int	size;

	ft_memset(info, 0, sizeof(t_ui_grid_info));
	info->pos.x = 0;
	info->pos.y = 0;
	info->size.x = board->ui.width;
	info->size.y = board->ui.height;
	size = min_int(board->ui.width, board->ui.height - UI_TEXTAREA_HEIGHT);
	info->grid_size.x = size;
	info->grid_size.y = size;
	size = min_int(info->grid_size.x / board->width, info->grid_size.y / board->height);
	info->cell_size.x = size;
	info->cell_size.y = size;
	info->coin_offset = UI_COIN_OFFSET_R * size;
	info->coin_radius = (size - info->coin_offset) / 2;
	info->coin_outline_radius = info->coin_radius + info->coin_offset / 8;
	info->first_launch = true;
	info->loop_count = 0;
	info->hovered_col = -1;
	info->selected_col = -1;
	info->grid_size.x = board->width * info->cell_size.x;
	info->grid_size.y = board->height * info->cell_size.y;
	info->text_position.x = 10;
	info->text_position.y = info->grid_size.y + 20;
}
