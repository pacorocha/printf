/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:06:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/09 22:29:45 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*chop_string(char *arg_str, int s_len, t_specs *spec)
{
	if (spec->prec_size < s_len)
	{
		arg_str = ft_substr(arg_str, 0, spec->prec_size);
		s_len = ft_strlen(arg_str);
		return (arg_str);
	}
	else
		return (arg_str);
}
void		get_string(va_list args, t_specs *spec)
{
	char	*arg_str;
	int		s_len;

	arg_str = va_arg(args, char *);
	spec->filler = ' ';
	if (arg_str == NULL)
		arg_str = "(null)";
	s_len = ft_strlen(arg_str);
	if (spec->precision == 0 && spec->lalign == 0 && spec->width > s_len)
		define_width(s_len, spec);
	arg_str = chop_string(arg_str, s_len, spec);
	if (spec->precision == 1 && spec->lalign == 0)
		print_fill(spec->width - s_len, spec);
	ft_putstr(arg_str);
	if (spec->lalign == 1)
	{
		if (spec->width > s_len)
			print_fill(spec->width - s_len, spec);
	}
	if (spec->prec_size < s_len)
		free(arg_str);
	spec->total_chars += s_len;
}
