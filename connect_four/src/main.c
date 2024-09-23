/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:54:58 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/08 20:18:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "connect.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "mlx.h"

static int	check_args(
	int argc,
	char *argv[],
	int *height,
	int *width,
	bool *ui_enabled
)
{
	if (argc != 3 && (argc != 4 || ft_strcmp(UI_PARAM, argv[3])))
	{
		ft_dprintf(STDERR_FILENO, "Bad argument number\n");
		return (-1);
	}
	if (ft_atoi_strict(argv[1], height) == -1
		|| ft_atoi_strict(argv[2], width) == -1)
	{
		ft_dprintf(STDERR_FILENO, "Invalid integer\n");
		return (-1);
	}
	if (*height < 6 || *width < 7)
	{
		ft_dprintf(STDERR_FILENO, "Bad input size\n");
		return (-1);
	}
	*ui_enabled = (argc == 4 && !ft_strcmp(UI_PARAM, argv[3]));
	return (0);
}

static void	launch_game(t_board *board)
{
	print_board(board);
	game_loop(board);
}

static void	launch_game_with_ui(t_board *board)
{
	if (board->width > UI_SIZE_MAX || board->height > UI_SIZE_MAX)
	{
		ft_dprintf(STDERR_FILENO, "The UI cannot handle the given size (width or height > %d)\n", UI_SIZE_MAX);
		return ;
	}
	if (!t_mlx_init(board, &board->ui))
	{
		ft_dprintf(STDERR_FILENO, "Error while initializing t_mlx\n");
		return ;
	}
	if (!t_mlx_launch(&board->ui))
	{
		ft_dprintf(STDERR_FILENO, "Error while launching t_mlx\n");
		return ;
	}
	if (!add_event_handlers(board))
	{
		ft_dprintf(STDERR_FILENO, "Error while adding event listeners\n");
		return ;
	}
	init_ui_grid_info(board, &board->ui_grid_info);
	mlx_loop(board->ui.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_board	board;
	int		height;
	int		width;
	bool	ui_enabled;
	
	srand(time(NULL));
	if (check_args(argc, argv, &height, &width, &ui_enabled) == -1)
		return (1);
	if (init_board(&board, height, width, ui_enabled) == -1)
	{
		free_board(&board);
		return (1);
	}
	if (!board.ui_enabled)
		launch_game(&board);
	else
		launch_game_with_ui(&board);
	free_board(&board);
	return (0);
}
