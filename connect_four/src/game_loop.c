/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:19:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/08 20:56:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

int	game_loop(t_board *board)
{
	int		next_col;
	char	next_coin = 0;

	if (board == NULL)
		return (-1);
	while (board->status == PLAYING)
	{
		next_col = 0;
		switch (board->curr_player)
		{
			case J1:
				next_coin = J1_COIN;
				next_col = get_player_input(board);
				break;
			case AI:
				next_coin = AI_COIN;
				next_col = get_ai_input(board);
				break;
		}
		if (put_next_coin(board, next_col, next_coin) == -1 ||  print_board(board) == -1)
			return (-1);
		board->curr_player *= -1;
	}
	return (print_status(board));
}
