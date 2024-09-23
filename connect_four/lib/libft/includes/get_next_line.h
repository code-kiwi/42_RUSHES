/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:46:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/06 06:19:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buff
{
	char	buff[BUFFER_SIZE];
	size_t	start;
	size_t	end;
}	t_buff;

char	*get_next_line(int fd);
char	*ft_strn2join_free_s1(char *s1, char *s2, size_t n1, size_t n2);

#endif
