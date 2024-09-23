/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_percent_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 11:01:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

/*
 *	Returns "%" allocated string
 *	When an error occurs NULL is returned
 */
char	*fpf_percent_manager(va_list args, t_input_format *input)
{
	if (args == NULL || input == NULL)
		return (NULL);
	return (ft_strdup("%"));
}
