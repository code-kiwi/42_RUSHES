/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 11:10:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "fpf_buffer.h"

# define NB_CONV 7
# define AVAILABLE_CONVS "discuxXp%"
# define VALID_FORMAT "0123456789 +-#."

typedef struct s_intput_format
{
	size_t	precision_val;
	size_t	length;
	size_t	length_result;
	char	format;
	bool	precision;
	bool	alternative;
	bool	space;
	bool	plus;
	bool	minus;
	bool	zero;
}	t_input_format;

typedef struct s_format_dispatch
{
	char	*flags;
	char	*(*f)(va_list args, t_input_format *input);
}	t_format_dispatch;

char			*(*dispatch_get_func(t_format_dispatch dispatch[NB_CONV], \
					char flag))(va_list args, t_input_format *input);
void			input_format_get_info(t_input_format *format_info, \
					const char *format, size_t format_end);

int				ft_dprintf(int fd, const char *format, ...) \
					__attribute__ ((format (printf, 2, 3)));
int				ft_printf(const char *format, ...) \
					__attribute__ ((format (printf, 1, 2)));

void			init_format_dispatch(t_format_dispatch dispatch[NB_CONV]);

size_t			fpf_get_format_end(const char *format);
bool			fpf_is_valid_format(char c);
bool			fpf_is_available_conversion(char c);

char			*fpf_int_manager(va_list args, t_input_format *input);
char			*fpf_uint_manager(va_list args, t_input_format *input);
char			*fpf_hexa_manager(va_list args, t_input_format *input);
char			*fpf_ptr_manager(va_list args, t_input_format *input);
char			*fpf_string_manager(va_list args, t_input_format *input);
char			*fpf_char_manager(va_list args, t_input_format *input);
char			*fpf_percent_manager(va_list args, t_input_format *input);
char			*fpf_formatter_precision(char *str, t_input_format *input, \
					int nb);
char			*fpf_formatter_length(char *str, t_input_format *input);
char			*fpf_formatter_plus_space(char *str, t_input_format *input);

char			*ft_ltoa_base(long nb, char *base);
char			*ft_prepend_chars(char *str, char c, size_t len_total);
char			*ft_append_chars(char *str, char c, size_t len_total);
char			*ft_ultoa_base(unsigned long nb, char *base);
char			*ft_ctoa(int c);
char			*ft_itoa(int n);
char			*ft_ltoa(long nb);
unsigned long	ft_atoul(const char *nb_ptr);
size_t			ft_get_long_len(long num, size_t base_len);
size_t			ft_get_ulong_len(unsigned long nb, size_t base_len);
bool			ft_is_valid_base(char *base);
int				ft_isspace(int c);

#endif
