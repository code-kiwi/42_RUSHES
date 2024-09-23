/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ai_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:42:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/08 20:56:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect.h"
#include "limits.h"
#include "ft_math.h"

int negamax(t_board *board, int depth, int alpha, int beta, int player);

int	eval_game(t_board *board, int player);
int	get_ai_input(t_board *board)
{
	int	best_col = 0;
	int	negamax_return;
	int	best_score;

	negamax_return = 0;
	best_score = -board->nb_slot;
	for (int coll = 0; coll < board->width; ++coll)
	{
		if (is_coll_full(board, board->coll_order[coll]) != -1)
		{
			if (check_for_win(board, board->coll_order[coll], AI_COIN))
			{
				negamax_return = board->nb_moves / 2 + 1;
				best_col = board->coll_order[coll];
				break ;
			}
			place_coin(board, board->coll_order[coll], AI_COIN);
			negamax_return = -negamax(board, board->depth,INT_MIN,INT_MAX, J1);
			remove_coin(board, board->coll_order[coll]);
			if (negamax_return > best_score)
			{
				best_col = board->coll_order[coll];
				best_score = negamax_return;
			}
		}
	}
	return (best_col);
}

int negamax(t_board *board, int depth, int alpha, int beta, int player)
{
	int	max_eval = INT_MIN;
	int	eval = 0;

	if(board->nb_moves == board->nb_slot || depth == 0)
		return (0);
	for(int x = 0; x < board->width; x++)
	{
		if(is_coll_full(board, x) != -1 && check_for_win(board, x, get_coin(player))) 
    	  return ((board->nb_slot - (board->nb_moves + 1)) / 2);
	}
	for(int x = 0; x < board->width; x++)
	{
	    if(is_coll_full(board, board->coll_order[x]) != -1)
		{
			place_coin(board, board->coll_order[x], get_coin(player));
			eval = -negamax(board, depth - 1, -beta, -alpha, -player);
			remove_coin(board, board->coll_order[x]);
			max_eval = ft_max(max_eval, eval);
			alpha = ft_max(alpha, eval);
			if (beta <= alpha)
				return (max_eval);
		}
	}
	return (max_eval);
}
