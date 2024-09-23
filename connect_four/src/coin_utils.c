/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:55:35 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 15:16:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"
#include "ft_printf.h"

int	put_next_coin(t_board *board, int next_col, char next_coin)
{
	if (next_col == -1)
	{
		ft_dprintf(STDERR_FILENO, "The column index is not valid\n");
		return (-1);
	}
	if (check_for_win(board, next_col, next_coin))
	{
		board->status = WIN;
		board->winner = next_coin;
	}
	place_coin(board, next_col, next_coin);
	if (board->nb_moves == (board->nb_slot) && board->status == PLAYING)
		board->status = DRAW;
	return (0);
}

char	get_coin(int player)
{
	return (player == J1 ? J1_COIN : AI_COIN);
}

void	place_coin(t_board *board, int coll, char coin)
{
	int	i;

	i = is_coll_full(board, coll);
	board->board[i][coll] = coin;
	board->nb_moves++;
}

void	remove_coin(t_board *board, int coll)
{
	int	i;

	if (coll > (board->width - 1) || coll < 0)
	{
		ft_dprintf(STDERR_FILENO, "debug wrong slot call in remove (%d)\n", coll);
		return ;
	}
	i = is_coll_full(board, coll) + 1;
	board->board[i][coll] = 0;
	board->nb_moves--;
}
