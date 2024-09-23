/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:55:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/23 08:24:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT_H
# define CONNECT_H

# include <stdbool.h>

# define J1						-1
# define AI						1
# define J1_COIN				'X'
# define AI_COIN				'0'

# define UI_PARAM				"-v"
# define UI_SIZE_MAX			100
# define UI_LOOP_FRAME_TARGET	1000
# define UI_WIDTH				880
# define UI_HEIGHT				1000
# define UI_TEXTAREA_HEIGHT		120
# define UI_COIN_OFFSET_R		0.2f
# define UI_TITLE				"Connect4"
# define J1_COIN_COLOR			0xFFFF00
# define AI_COIN_COLOR			0xFF0000
# define HL_COIN_COLOR			0xBBBBBB
# define UI_BG_COLOR			0xFFFFFF
# define UI_GRID_COLOR			0x34A4EB
# define UI_OUTLINE_COLOR		0x024975

# define KEY_ESC				65307
# define MOUSE_LEFT				1

typedef enum e_status
{
	PLAYING,
	WIN,
	DRAW,
}	t_status;

typedef struct s_mlx_coords
{
	int	x;
	int	y;
}	t_mlx_coords;

typedef struct s_ui_grid_info
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_mlx_coords	grid_size;
	t_mlx_coords	cell_size;
	t_mlx_coords	text_position;
	int				coin_offset;
	int				coin_radius;
	int				coin_outline_radius;
	bool			first_launch;
	int				loop_count;
	int				hovered_col;
	int				selected_col;
}	t_ui_grid_info;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		bpp_factor;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	*img1;
	t_image	*img2;
	t_image	*img_buff;
	int		width;
	int		width_half;
	int		height;
	int		height_half;
	char	*title;
}	t_mlx;

enum e_mlx_event
{
	MLX_ON_KEYPRESS = 2,
	MLX_ON_KEYRELEASE = 3,
	MLX_ON_MOUSEDOWN = 4,
	MLX_ON_MOUSEUP = 5,
	MLX_ON_MOUSEMOVE = 6,
	MLX_ON_EXPOSE = 12,
	MLX_ON_DESTROY = 17
};

enum e_hook_type
{
	HOOK_DESTROY,
	HOOK_KEY,
	HOOK_KEY_RELEASE,
	HOOK_KEY_PRESS,
	HOOK_MOUSE_PRESS,
	HOOK_MOUSE_RELEASE,
	HOOK_MOUSE_MOVE,
	HOOK_LOOP
};

typedef struct s_board
{
	char			**board;
	int				nb_moves;
	int				nb_slot;
	int				height;
	int				width;
	int				width_in_char;
	t_status		status;
	char			winner;
	int				*coll_order;
	int				curr_player;
	bool			ui_enabled;
	t_mlx			ui;
	t_ui_grid_info	ui_grid_info;
	int				depth;
}	t_board;

int		print_board(t_board *board);
int		print_slot(t_board *board, int col);
int		print_status(t_board *board);

int		get_width_in_char(int width);



int		init_board(t_board *board, int height, int width, bool ui_enabled);
void	init_ui_grid_info(t_board *board, t_ui_grid_info *info);
void	free_board(t_board *board);

int		game_loop(t_board *board);
int		check_for_win(t_board *board, int coll, char coin);
int		is_coll_full(t_board *board, int coll);
int		is_valid_equal(t_board *board, int row, int coll, char coin);

int		put_next_coin(t_board *board, int next_col, char next_coin);
char	get_coin(int player);
void	place_coin(t_board *board, int coll, char coin);
void	remove_coin(t_board *board, int coll);

int		get_player_input(t_board *board);
int		get_ai_input(t_board *board);
int		get_match_sum(t_board *board, int coll, int row, char coin);
int		get_match_sum2(t_board *board, int coll, int row);

int		game_loop_ui(t_board *board);
bool	t_mlx_init(t_board *board, t_mlx *ui);
bool	t_mlx_launch(t_mlx *ui);
void	t_mlx_destroy(t_mlx *ui);
void	t_mlx_center_cursor(t_mlx *mlx);
bool	t_mlx_add_hook(t_mlx *ui, int (*handler)(), void *data, enum e_hook_type hook_type);
bool	t_mlx_render(t_mlx *ui);
bool	add_event_handlers(t_board *board);

void	t_mlx_draw_pixel(t_image *img, t_mlx_coords *coords, unsigned int color);
void	t_mlx_draw_circle(t_image *img, t_mlx_coords *coords, int radius, unsigned int color);
void	t_mlx_draw_disk(t_image *img, t_mlx_coords *coords, int radius, unsigned int color);
void	t_mlx_draw_line(t_image *img, t_mlx_coords coords_start, t_mlx_coords coords_end, unsigned int color);
void	t_mlx_draw_rect(t_image *img, t_mlx_coords *pos, t_mlx_coords *size, unsigned int color);

t_image	*t_image_init(void *mlx_ptr, int img_width, int img_height);
void	t_image_destroy(void *mlx_ptr, t_image *img, bool free_ptr);

int		min_int(int a, int b);
int		max_int(int a, int b);

#endif
