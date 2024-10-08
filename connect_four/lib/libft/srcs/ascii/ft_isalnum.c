/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:45:20 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 02:47:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
