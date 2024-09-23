/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coll_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:56:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 12:49:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"

int	is_coll_full(t_board *board, int coll)
{
	int	i;

	if (coll < 0 || coll > (board->width - 1))
		return (-1);
	i = board->height - 1;
	while (i >= 0)
	{
		if (board->board[i][coll])
			--i;
		else
			return (i);
	}
	return (i);
}
