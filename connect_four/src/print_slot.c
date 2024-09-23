/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_slot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 04:50:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 11:39:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "connect.h"
#include "ft_printf.h"

int	print_slot(t_board *board, int col)
{
	int	row = is_coll_full(board, col);
	char		c;

	if (row == -1)
		row = 0;
	c = board->board[row][col];
	if (c == 0)
		c = ' ';
	if (ft_printf("print slot: %c \n", c) < 0)
		return (-1);
	return (0);
}
