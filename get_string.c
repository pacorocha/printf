/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:06:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/26 19:56:45 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	define_width(char *arg_str, int s_len, t_specs spec)
{
	int output;

	if (spec.width > s_len && spec.prec_size < s_len)
		output = spec.prec_size - s_len;
	if (spec.width > s_len && spec.prec_size > s_len)
		output = spec.width - s_len;
	if (spec.width <= s_len && spec.prec_size < s_len)
	{
		output = spec.width - spec.prec_size;
		arg_str = ft_substr(arg_str, 0, spec.prec_size);
	}
	return (output);
}

void		get_string(int i, va_list args, t_specs spec)
{
	char	*arg_str;
	int		s_len;
	int		output;

	arg_str = va_arg(args, char *);
	spec.filler = ' ';
	if (arg_str == NULL)
	{
		arg_str = "(null)";
		output = spec.width - 5;
		print_fill(output, i, spec);
	}
	s_len = ft_strlen(arg_str);
	if (spec.width > 0 && spec.lalign == 0)
	{
		define_width(arg_str, s_len, spec);
		print_fill(output, i, spec);
	}
	ft_putstr(arg_str);
	if (spec.width > 0 && spec.lalign == 1)
	{
		if (spec.width > s_len)
			output = spec.width - s_len;
		print_fill(output, i, spec);
	}
}
