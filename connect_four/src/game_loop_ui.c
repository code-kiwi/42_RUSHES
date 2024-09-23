/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:59:00 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/08 20:57:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"
#include "mlx.h"
#include "ft_printf.h"

static void	draw_grid(t_board *board, t_ui_grid_info *info);
static void display_game_state(t_board *board, t_ui_grid_info *info);
static int	print_player_choice(int col);

int	game_loop_ui(t_board *board)
{
	int	next_col = 0;
	int	next_coin = 0;

	if (board == NULL)
		return (0);
	if (board->ui_grid_info.first_launch)
	{
		if (print_board(board) < 0)
		{
			mlx_loop_end(board->ui.mlx_ptr);
			return (0);
		}
		draw_grid(board, &board->ui_grid_info);
		t_mlx_render(&board->ui);
		display_game_state(board, &board->ui_grid_info);
		board->ui_grid_info.first_launch = false;
	}
	board->ui_grid_info.loop_count++;
	if (board->status == PLAYING && board->ui_grid_info.loop_count >= UI_LOOP_FRAME_TARGET)
	{
		board->ui_grid_info.loop_count = 0;
		switch (board->curr_player)
		{
			case J1:
				next_coin = J1_COIN;
				if (board->ui_grid_info.selected_col == -1 || is_coll_full(board, board->ui_grid_info.selected_col) == -1)
				{
					draw_grid(board, &board->ui_grid_info);
					t_mlx_render(&board->ui);
					display_game_state(board, &board->ui_grid_info);
					return (0);
				}
				next_col = board->ui_grid_info.selected_col;
				print_player_choice(next_col);
				board->ui_grid_info.selected_col = -1;
				break;
			case AI:
				next_coin = AI_COIN;
				next_col = get_ai_input(board);
				board->ui_grid_info.selected_col = -1;
				break;
		}
		if (put_next_coin(board, next_col, next_coin) == -1)
		{
			mlx_loop_end(board->ui.mlx_ptr);
			return (0);
		}
		board->curr_player *= -1;
		draw_grid(board, &board->ui_grid_info);
		t_mlx_render(&board->ui);
		display_game_state(board, &board->ui_grid_info);
		if (print_board(board) < 0 && board->status != PLAYING && print_status(board) < 0)
		{
			mlx_loop_end(board->ui.mlx_ptr);
			return (0);
		}
	}
	return (0);
}

static int	print_player_choice(int col)
{
	return (ft_printf("Player selected the column: %d\n", col + 1));
}

static void display_game_state(t_board *board, t_ui_grid_info *info)
{
	char	*str;

	switch (board->status)
	{
		case WIN:
			str = board->winner == J1_COIN ? "PLAYER 1 WINS" : "AI WINS";
			break;
		case PLAYING:
			str = board->curr_player == J1 ? "PLAYER 1's TURN" : "AI'S TURN";
			break;
		case DRAW:
			str = "DRAW";
			break;
		default:
			str = "";
	}
	mlx_string_put(board->ui.mlx_ptr, board->ui.mlx_win, info->text_position.x, info->text_position.y, 0x000000, str);
}

static void	draw_grid(t_board *board, t_ui_grid_info *info)
{
	t_mlx_coords	center;
	t_mlx_coords	outline_pos, outline_size;
	unsigned int	color;
	int				highlighted_row;

	// BG ang GRID
	t_mlx_draw_rect(board->ui.img_buff, &info->pos, &info->size, UI_BG_COLOR);
	t_mlx_draw_rect(board->ui.img_buff, &info->pos, &info->grid_size, UI_GRID_COLOR);

	// Horizontal outlines
	outline_pos.x = 0;
	outline_size.x = info->cell_size.x * board->width;
	outline_size.y = 4;	
	for (int row = 0; row <= board->height; row++)
	{
		outline_pos.y = max_int(0, row * info->cell_size.y - 2);
		t_mlx_draw_rect(board->ui.img_buff, &outline_pos, &outline_size, UI_OUTLINE_COLOR);
	}

	// Vertical outlines
	outline_pos.y = 0;
	outline_size.x = 3;
	outline_size.y = info->cell_size.y * board->height;
	for (int col = 0; col <= board->width; col++)
	{
		outline_pos.x = max_int(0, col * info->cell_size.x - 2);

		t_mlx_draw_rect(board->ui.img_buff, &outline_pos, &outline_size, UI_OUTLINE_COLOR);
	}

	// Disks
	for (int row = 0; row < board->height; row++)
	{
		center.y = row * info->cell_size.y + info->cell_size.y / 2;
		for (int col = 0; col < board->width; col++)
		{
			center.x = col * info->cell_size.x + info->cell_size.x / 2;
			t_mlx_draw_disk(board->ui.img_buff, &center, info->coin_outline_radius, UI_OUTLINE_COLOR);
			switch (board->board[row][col])
			{
				case J1_COIN:
					color = J1_COIN_COLOR;
					break;
				case AI_COIN:
					color = AI_COIN_COLOR;
					break;
				default:
					color = UI_BG_COLOR;
					break;
			}
			t_mlx_draw_disk(board->ui.img_buff, &center, info->coin_radius, color);
		}
	}

	// Highlighted disk
	if (!info->first_launch && info->hovered_col != -1 && board->curr_player == J1 && board->status == PLAYING)
	{
		highlighted_row = is_coll_full(board, info->hovered_col);
		if (highlighted_row < 0)
			return ;
		center.x = info->hovered_col * info->cell_size.x + info->cell_size.x / 2;
		center.y = highlighted_row * info->cell_size.y + info->cell_size.y / 2;
		t_mlx_draw_disk(board->ui.img_buff, &center, info->coin_radius, HL_COIN_COLOR);
	}
}
