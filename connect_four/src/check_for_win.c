/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:51:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/07 13:25:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"
#include "ft_printf.h"

static int	check_diag2(t_board *board, int row, int coll, char coin);
static int	check_diag(t_board *board, int row, int coll, char coin);
static int	check_coll(t_board *board, int row, int coll, char coin);
static int	check_row(t_board *board, int row, int coll, char coin);

int	check_for_win(t_board *board, int coll, char coin)
{
	int	row;

	row = is_coll_full(board, coll);
	if (row == -1)
		return (0);
	if (check_row(board, row, coll, coin))
		return (1);
	if (check_coll(board, row, coll, coin))
		return (1);
	if (check_diag(board, row, coll, coin))
		return (1);
	if (check_diag2(board, row, coll, coin))
		return (1);
	return (0);
}

static int	check_row(t_board *board, int row, int coll, char coin)
{
	int	i;
	int	match;

	match = 0;
	i = 1;
	while (is_valid_equal(board, row, coll + i, coin) && match < 3)
	{
		++i;
		++match;
	}
	i = 1;
	while (is_valid_equal(board, row, coll - i, coin) && match < 3)
	{
		++i;
		++match;
	}
	return (match == 3);
}

static int	check_coll(t_board *board, int row, int coll, char coin)
{
	int	i;
	int	match;

	match = 0;
	i = 1;
	while (is_valid_equal(board, row + i, coll, coin) && match < 3)
	{
		++i;
		++match;
	}
	i = 1;
	while (is_valid_equal(board, row - i, coll, coin) && match < 3)
	{
		++i;
		++match;
	}
	return (match == 3);
}

static int	check_diag(t_board *board, int row, int coll, char coin)
{
	int	i;
	int	match;

	match = 0;
	i = 1;
	while (is_valid_equal(board, row + i, coll + i, coin) && match < 3)
	{
		++i;
		++match;
	}
	i = 1;
	while (is_valid_equal(board, row - i, coll - i, coin) && match < 3)
	{
		++i;
		++match;
	}
	return (match == 3);
}

static int	check_diag2(t_board *board, int row, int coll, char coin)
{
	int	i;
	int	match;

	match = 0;
	i = 1;
	while (is_valid_equal(board, row - i, coll + i, coin) && match < 3)
	{
		++i;
		++match;
	}
	i = 1;
	while (is_valid_equal(board, row + i, coll - i, coin) && match < 3)
	{
		++i;
		++match;
	}
	return (match == 3);
}
