/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:53:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/06 06:28:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "get_next_line.h"
#include "ft_string.h"
#include "stdlib.h"
#include "unistd.h"
#include <stddef.h>

int		join_line(t_buff *buff, char **line, size_t *line_len);
void	joinchr(t_buff *buff, size_t line_len, char **line, char **ptr);
ssize_t	read_lines(int fd, t_buff *buff);
char	*ft_strn2join_free_s1(char *s1, char *s2, size_t n1, size_t n2);

char	*get_next_line(int fd)
{
	static t_buff	buff = {{0}, 0, 0};
	char			*line;
	size_t			line_len;
	char			*ptr;
	ssize_t			ret;

	line = NULL;
	line_len = 0;
	while (ft_strnchr(buff.buff + buff.start, \
					'\n', buff.end - buff.start) == NULL)
	{
		if (buff.end != buff.start)
			if (join_line(&buff, &line, &line_len) == -1)
				return (free(line), NULL);
		ret = read_lines(fd, &buff);
		if (ret < 0)
			return (buff.end = 0, free(line), NULL);
		if (ret == 0)
			return (line);
	}
	joinchr(&buff, line_len, &line, &ptr);
	if (line == NULL)
		return (free(line), NULL);
	return (buff.start = ptr - buff.buff, line);
}

ssize_t	read_lines(int fd, t_buff *buff)
{
	ssize_t	ret;

	(*buff).start = 0;
	ret = read(fd, (*buff).buff, BUFFER_SIZE);
	buff->end = ret;
	return (ret);
}

void	joinchr(t_buff *buff, size_t line_len, char **line, char **ptr)
{
	*ptr = ft_strnchr(buff->buff + buff->start, \
					'\n', \
					buff->end - buff->start) + 1;
	*line = ft_strn2join_free_s1(*line, \
								buff->buff + (*buff).start, \
								*ptr - (buff->buff + buff->start), \
								line_len);
}

int	join_line(t_buff *buff, char **line, size_t *line_len)
{
	*line = ft_strn2join_free_s1(*line, \
								buff->buff + buff->start, \
								buff->end - buff->start, \
								*line_len);
	*line_len += buff->end - buff->start;
	if (!(*line))
		return (-1);
	return (0);
}

char	*ft_strn2join_free_s1(char *s1, char *s2, size_t n1, size_t n2)
{
	char	*str;
	size_t	l_s1;

	l_s1 = 0;
	if (s1)
		l_s1 = n2;
	str = malloc(sizeof(char) * (l_s1 + n1 + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, l_s1);
	ft_memcpy(str + l_s1, s2, n1);
	str[l_s1 + n1] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);
}
