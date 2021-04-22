/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/21 23:06:57 by jfrancis         ###   ########.fr       */
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
	}
	if (n < 0)
	{
		negative_case(n, spec);
		number = ft_substr(number, 1, n_len);
		ft_putnbr(number, n_len, spec);
		free(number);
	}
	if (n >= 0 && spec->width > spec->prec_size && spec->lalign == 0)
	{
		spec->filler = ' ';
		output = spec->width - spec->prec_size;
		print_fill(output, spec);
	}
	if (n >= 0 && spec->prec_size >= 1 && spec->precision == 1 && (spec->lalign == 1 || spec->prec_size > spec->width))
	{
		spec->filler = '0';
		output = spec->prec_size - n_len;
		print_fill(output, spec);
		if (spec->prec_size > spec->width)
			spec->lalign = 1;
	}
	if (n > 0 || (n == 0 && (spec->precision == 0 || (spec->prec_size > 0 && spec->prec_size >= spec->width))))
		ft_putnbr(number, n_len, spec);
	if (n < 0)
		n_len++;
	if (n > 0 && spec->width > spec->prec_size && (spec->precision == 1 || spec->lalign == 1))
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len;
		else
			output = spec->width - spec->prec_size;
		print_fill(output, spec);
	}
	if (n >= 0 && spec->precision ==  1 && spec->prec_size >= 1 && (spec->precision == 0 || spec->lalign == 0))
	{
		spec->filler = '0';
		output = spec->prec_size - n_len;
		print_fill(output, spec);
	}
	if (n == 0 && spec->precision ==  1 && spec->prec_size >= 1 && spec->width > spec->prec_size)
	{
		spec->filler = '0';
		output = spec->width - spec->prec_size;
		print_fill(output, spec);
	}
	if (n == 0 && spec->width > spec->prec_size && (spec->precision == 1 || spec->lalign == 1))
	{
		spec->filler = ' ';
		if (spec->prec_size < n_len)
			output = spec->width - n_len;
		else
			output = spec->prec_size - n_len;
		print_fill(output, spec);
	}
	// printf("width: %i, precision: %i, prec_size: %i - lalign: %i, filler: %c, n: %i, n_len: %i", spec->width, spec->precision, spec->prec_size, spec->lalign, spec->filler, n, n_len);
}
