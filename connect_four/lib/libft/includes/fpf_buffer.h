/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_buffer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:44:15 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 10:05:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPF_BUFFER_H
# define FPF_BUFFER_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include <unistd.h>

# define FPF_BUFFER_SIZE 1000

typedef struct s_fpf_buffer
{
	char	content[FPF_BUFFER_SIZE];
	size_t	max_size;
	size_t	next_index;
	size_t	total_len;
	bool	error;
	int		fd;
	void	(*flush)(struct s_fpf_buffer *buffer);
	size_t	(*get_available_size)(struct s_fpf_buffer * buffer);
	void	(*set_error)(struct s_fpf_buffer *buffer);
	void	(*add_char)(struct s_fpf_buffer *buffer, char c);
	void	(*add_char_secure)(struct s_fpf_buffer *buffer, char c);
	void	(*add_chars_secure)(
			struct s_fpf_buffer *buffer,
			char *str,
			size_t nb_chars
			);
	void	(*add_str)(struct s_fpf_buffer *buffer, char *str);
	void	(*add_str_secure)(struct s_fpf_buffer *buffer, char *str);
	void	(*put_fd)(struct s_fpf_buffer *buffer);
}	t_fpf_buffer;

t_fpf_buffer	buffer_init(int fd);
void			buffer_flush(t_fpf_buffer *buffer);
size_t			buffer_get_available_size(t_fpf_buffer *buffer);
void			buffer_set_error(t_fpf_buffer *buffer);
void			buffer_add_char(t_fpf_buffer *buffer, char c);
void			buffer_add_char_secure(t_fpf_buffer *buffer, char c);
void			buffer_add_chars_secure(
					t_fpf_buffer *buffer,
					char *str,
					size_t nb_chars
					);
void			buffer_add_str(t_fpf_buffer *buffer, char *str);
void			buffer_add_str_secure(t_fpf_buffer *buffer, char *str);
void			buffer_put_fd(t_fpf_buffer *buffer);

#endif
