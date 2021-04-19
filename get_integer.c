/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/18 22:23:07 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_putnbr(char *number, int n_len, t_specs *spec)
{
	ft_putstr(number);
	spec->total_chars += n_len;
}

void		get_integer(va_list args, t_specs *spec)
{
	int		n;
	char	*number;
	int		n_len;
	int		output;

	n = va_arg(args, int);
	number = ft_itoa(n);
	n_len = num_size(n);
	output = 0;
	if (n == 0)
	{
		number= "0";
		n_len = 1;
		if (spec->precision == 0 && spec->prec_size == 0)
			spec->prec_size = 1;
		if (spec->precision == 1)
			spec->filler = '0';
		if (spec->prec_size - spec->width > n_len && spec->width != 0 &&
		spec->lalign == 1)
			number = " ";
	}
	if (n > 0 && spec->lalign == 0 && spec->width > spec->prec_size)
		define_width(n_len, spec);
	if (n== 0 && spec->lalign == 1 && spec->prec_size > 0)
		print_fill(spec->prec_size - n_len, spec);
	if (n < 0)
	{
		negative_case(n, spec);
		number = ft_substr(number, 1, n_len);
		ft_putnbr(number, n_len, spec);
		free(number);
	}
	if ((n > 0 && (spec->prec_size > 1 || spec->width > 1)) || (n == 0 && spec->lalign == 0))
	{
		spec->filler = '0';
		spec->lalign = 0;
		print_fill(spec->prec_size - n_len, spec);
	}
	if ((n >= 0 && (spec->prec_size > 1 || spec->width> 1)) || (n == 0 && spec->precision == 0))
		ft_putnbr(number, n_len, spec);
	if (n < 0)
		n_len++;
	if (spec->prec_size >= n_len || spec->width > n_len || spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->width >= spec->prec_size + n_len || n_len == 1)
			output = spec->width - spec->prec_size;
		if (spec->width > spec->prec_size && spec->prec_size <= n_len)
			output = spec->width - n_len;
		if (spec->width > spec->prec_size && spec->lalign == 0 && n < 0)
			output = 0;
		print_fill(output, spec);
	}
	if (spec->prec_size - spec->width > n_len && spec->lalign == 1 && spec->width != 0 && n >= 0)
		print_fill(spec->prec_size - 1, spec);
	// printf("width: %i, precision: %i, prec_size: %i - lalign: %i, filler: %c, n: %i", spec->width, spec->precision, spec->prec_size, spec->lalign, spec->filler, n);
}
