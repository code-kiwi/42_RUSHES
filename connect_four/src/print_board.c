/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:04:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/08 18:43:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "connect.h"
#include "ft_stdio.h"
#include "ft_printf.h"

static int	print_number_line(t_board *board);

int	print_board(t_board *board)
{
	int	i;
	int	j;
	int limit;
	int	nb_space;

	i = 0;
	nb_space = board->width_in_char - 1;
	limit = (board->width_in_char - 1) / 2;
	if (nb_space % 2 == 1)
		limit++;
	ft_printf("\n");
	print_number_line(board);
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			ft_printf("|");

			for (int k = 0; k < limit; k++)
				ft_printf(" ");

			if (board->board[i][j])
				ft_printf("%c", board->board[i][j]);
			else
				ft_printf(" ");
			
			for (int k = limit + 1; k < board->width_in_char; k++)
				ft_printf(" ");

			++j;
		}
		ft_printf("|\n");
		++i;
	}
	ft_printf("\n");
	return (0);
}

static int	print_number_with_spaces(int nb, int total_width)
{
	int	nb_width;
	int	nb_space;
	int	limit;
	int	i;

	nb_width = get_width_in_char(nb);
	nb_space = total_width - nb_width;
	limit = nb_space / 2;
	if (nb_space % 2 == 1)
		limit++;
	i = 0;
	while (i < limit)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("%d", nb);
	i = limit + nb_width;
	while (i < total_width)
	{
		ft_printf(" ");
		i++;
	}
	return (0);
}

static int	print_number_line(t_board *board)
{
	for (int i = 0; i < board->width; i++)
	{
		ft_printf("-");
		print_number_with_spaces(i + 1, board->width_in_char);
	}
	ft_printf("-\n");
	return (0);
}
