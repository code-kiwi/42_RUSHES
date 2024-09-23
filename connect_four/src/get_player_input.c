/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:42:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 14:46:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "connect.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int	get_player_input_process(t_board *board);

int	get_player_input(t_board *board)
{
	int	player_input;

	player_input = -1;
	do
	{
		player_input = get_player_input_process(board);
		if (errno)
			return (-1);
	} while (player_input == -1);
	return (player_input);
}

static int	get_player_input_process(t_board *board)
{
	char	*line;
	int		input;

	if (ft_printf("Player select a column to play: ") == -1)
		return (-1);
	line = get_next_line(STDIN_FILENO);
	if (line == NULL)
		return (-1);
	if (ft_atoi_strict(line, &input) == -1)
	{
		free(line);
		ft_dprintf(STDERR_FILENO, "Invalid input !\n");
		return (-1);
	}
	free(line);
	if (input > 0 && input <= board->width)
	{
		if (is_coll_full(board, input - 1) == -1)
		{
			ft_dprintf(STDERR_FILENO, "This column is full !\n");
			return (-1);
		}
		return (input - 1);
	}
	ft_dprintf(STDERR_FILENO, "Invalid input !\n");
	return (-1);
}
