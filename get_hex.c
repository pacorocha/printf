/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/05 20:29:40 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			get_hex(char c, va_list args, t_specs *spec)
{
	unsigned long int	x;
	int					n_len;
	int					output;
	char				*hex_out;

	x = va_arg(args, unsigned long int);
	n_len = hex_size(x);
	hex_out = "";
	hex_out = hextoa(x, c, spec);
	if (spec->width >= 0 && spec->lalign == 0)
	{
		if (spec->precision == 0 && spec->filler == '0')
			spec->filler = '0';
		else
			spec->filler = ' ';
		output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		if (spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		print_fill(spec->prec_size - n_len, spec);
	}
	if (x > 0 || (x == 0 && (spec->precision == 0 || spec->prec_size > 0)))
	{
		ft_putstr(hex_out);
		free(hex_out);
	}
	else
		spec->total_chars--;
	if (spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len;
		else
			output = spec->width - spec->prec_size;
		if (spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
}
