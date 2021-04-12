/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/11 21:57:35 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			get_hex(char c, va_list args, t_specs *spec)
{
	unsigned long int	x;
	int					n_len;
	char				*hex_out;

	x = va_arg(args, unsigned long int);
	n_len = hex_size(x);
	hex_out = "";
	hex_out = hextoa(x, c, spec);
	ft_putstr(hex_out);
	free(hex_out);
	if (spec->lalign == 1)
		print_fill(spec->width - n_len, spec);
}
