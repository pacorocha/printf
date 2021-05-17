/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 21:30:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	prefix_hex(unsigned long x, long n_len,
						t_specs *spec)
{
	int	i;

	i = 2;
	if (!x)
		x = 0;
	if (!x && spec->precision == 1)
	{
		n_len = 0;
		print_fill(spec->width - n_len - i, spec);
	}
	else if (!x && spec->width > 0 && spec->minus == 0)
		print_fill(spec->width - n_len - i, spec);
	else
	{
		spec->width = spec->width - i;
		if (spec->width > (n_len + i) && spec->lalign == 0)
			print_fill(spec->width - n_len, spec);
	}
	write(1, "0x", i);
	if (spec->precision == 1 && spec->prec_size > n_len)
	{
		spec->filler = '0';
		print_fill(spec->prec_size - n_len, spec);
	}
	spec->total_chars = spec->total_chars + i;
}

void	get_pointer(va_list args, t_specs *spec)
{
	unsigned long int	x;
	int					n_len;
	char				*hex_out;

	x = va_arg(args, unsigned long int);
	n_len = hex_size(x);
	hex_out = "";
	prefix_hex(x, n_len, spec);
	hex_out = hextoa(x, 'p', spec);
	if (!x && spec->precision == 1)
		spec->total_chars--;
	else
		ft_putstr(hex_out);
	free(hex_out);
	if (spec->lalign == 1)
		print_fill(spec->width - n_len, spec);
}
