/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:19:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 13:22:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"

int	is_valid_equal(t_board *board, int row, int coll, char coin)
{
	if (
		row >= 0 && row < board->height
		&& coll >= 0 && coll < board->width
		&& board->board[row][coll] == coin
	)
		return (1);
	return (0);
}
