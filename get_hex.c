/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/09 23:27:55 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	hex_right_align_fill(unsigned int n, int n_len, t_specs *spec)
{
	int		output;

	if (spec->width >= 1 && spec->lalign == 0)
	{
		if (spec->precision == 0 && spec->filler == '0')
			spec->filler = '0';
		else
			spec->filler = ' ';
		if (spec->precision == 0)
			output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size <= n_len)
			output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		if (spec->precision == 1 && spec->prec_size == 0)
			output = spec->width - n_len;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		print_fill(spec->prec_size - n_len, spec);
	}
}

static void	hex_left_align_fill(int n, int n_len, t_specs *spec)
{
	int	output;

	if (n >= 0 && spec->width && spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len;
		else
			output = spec->width - spec->prec_size;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (n < 0 && spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len;
		if (spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		print_fill(output, spec);
	}
}

void	get_hex(char c, va_list args, t_specs *spec)
{
	unsigned int	x;
	int				n_len;
	char			*hex_out;

	x = va_arg(args, unsigned int);
	hex_out = "";
	hex_out = hextoa(x, c, spec);
	n_len = ft_strlen(hex_out);
	hex_right_align_fill(x, n_len, spec);
	if (x > 0 || (x == 0 && (spec->precision == 0 || spec->prec_size > 0)))
		ft_putstr(hex_out);
	else
		spec->total_chars--;
	hex_left_align_fill(x, n_len, spec);
	free(hex_out);
}
