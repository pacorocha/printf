/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/11 22:00:33 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		prefix_hex(unsigned long x, long n_len,
						t_specs *spec)
{
	int	i;

	i = 0;
	if (!x)
		x = 0;
	i = 2;
	spec->width = spec->width - i;
	if (spec->width > (n_len + i) && spec->lalign == 0)
		print_fill(spec->width - n_len, spec);
	write(1, "0x", i);
	spec->total_chars = spec->total_chars + i;
}

void			get_pointer(va_list args, t_specs *spec)
{
	unsigned long int	x;
	int					n_len;
	char				*hex_out;

	x = va_arg(args, unsigned long int);
	n_len = hex_size(x);
	hex_out = "";
	prefix_hex(x, n_len, spec);
	hex_out = hextoa(x, 'p', spec);
	ft_putstr(hex_out);
	free(hex_out);
	if (spec->lalign == 1)
		print_fill(spec->width - n_len, spec);
}
