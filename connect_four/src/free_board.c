/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 01:35:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 19:37:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "connect.h"

void	free_board(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->height && board->board[i] != NULL)
	{
		free(board->board[i]);
		++i;
	}
	free(board->board);
	free(board->coll_order);
	if (board->ui_enabled)
		t_mlx_destroy(&board->ui);
}
