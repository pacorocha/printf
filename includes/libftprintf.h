/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:50:27 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/26 19:43:22 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef	struct	s_ft_printf
{
	int			width;
	int			lalign;
	int			precision;
	int			prec_size;
	char		filler;
}				t_specs;

void			ft_putchar(char c);
int				ft_putstr(const char *str);
int				ft_printf(const char *str, ...);
void			check_params(const char *str, int i, va_list args,
				t_specs spec);
void			get_char(int i, va_list args, t_specs spec);
void			get_string(int i, va_list args, t_specs spec);
int				define_number(const char *str, int i, t_specs *spec);
int 			print_fill(int output, int i, t_specs spec);

#endif
