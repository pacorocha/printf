/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:06:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/04 14:10:13 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		get_string(va_list args, t_specs *spec)
{
	char	*arg_str;
	int		s_len;
	int		output;

	arg_str = va_arg(args, char *);
	spec->filler = ' ';
	if (arg_str == NULL)
		arg_str = "(null)";
	s_len = ft_strlen(arg_str);
	if (spec->precision == 0 && spec->lalign == 0)
		define_width(s_len, spec);
	if (spec->precision == 1 && spec->lalign == 0)
	{
		arg_str = ft_substr(arg_str, 0, spec->prec_size);
		s_len = ft_strlen(arg_str);
		output = spec->width - s_len;
		print_fill(output, spec);
	}
	ft_putstr(arg_str);
	if (spec->lalign == 1)
	{
		if (spec->width > s_len)
			output = spec->width - s_len;
		print_fill(output, spec);
	}
}
