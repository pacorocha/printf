/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:50:27 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 21:01:23 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef	struct	s_ft_printf
{
	int			start_format;
	int			width;
	int			lalign;
	int			precision;
	int			prec_size;
	char		filler;
	int			minus;
	char		*params;
	char		*flags;
	int			total_chars;
}				t_specs;

void			ft_putnbr(char *number, int n_len, t_specs *spec);
void			ft_putchar(char c);
int				ft_putstr(const char *str);
int				set_format(const char *str, int i, va_list args, t_specs *spec);
int				ft_printf(const char *str, ...);
int				set_flags(const char *str, int i, va_list args, t_specs *spec);
int				get_wildcard_value(va_list args, t_specs *spec);
void			check_params(char c, va_list args,
				t_specs *spec);
void			get_char(char c, va_list args, t_specs *spec);
void			get_string(va_list args, t_specs *spec);
void			get_integer(va_list args, t_specs *spec);
void			get_u_int(va_list args, t_specs *spec);
void			get_pointer(va_list args, t_specs *spec);
void			get_hex(char c, va_list args, t_specs *spec);
int				define_number(const char *str, int i, t_specs *spec);
void			define_width(int s_len, t_specs *spec);
void			print_fill(int output, t_specs *spec);
void			left_align_fill(int n, int n_len, t_specs *spec);
void			right_align_fill(int n, int n_len, t_specs *spec);
void			negative_case(int n, t_specs *spec);
char			*hextoa(unsigned long int x, char c, t_specs *spec);
unsigned long	hex_size(unsigned long int n);

#endif
