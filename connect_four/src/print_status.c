/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:51:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 14:52:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"
#include "ft_printf.h"

int	print_status(t_board *board)
{
	switch (board->status)
	{
		case WIN:
			if (ft_printf("Player with %c won!\n", board->winner) < 0)
				return (-1);
			break;
		case DRAW:
			if (ft_printf("Its a draw !\n") < 0)
				return (-1);
			break;
		default:
			ft_dprintf(STDERR_FILENO, "Invalid status\n");
			return (-1);
			break;
	}
	return (0);
}
