/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:30:13 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/10 00:49:54 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	u_right_align_fill(unsigned int n, int n_len, t_specs *spec)
{
	int	output;

	if (spec->width >= 0 && spec->lalign == 0)
	{
		if (spec->precision == 0 && spec->filler == '0')
			spec->filler = '0';
		else
			spec->filler = ' ';
		output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		if (spec->precision == 1 && spec->prec_size == 0 && spec->prec_set == 1)
			output++;
		if (n == 0 && spec->precision == 1 && spec->prec_set == 0)
			output = spec->width;
		if (n > 2147483647 && spec->prec_size == 0 && spec->precision == 1)
			output--;
		print_fill(output, spec);
	}
	if (spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		print_fill(spec->prec_size - n_len, spec);
	}
}

void	u_left_align_fill(unsigned int n, int n_len, t_specs *spec)
{
	int	output;

	if (spec->width > 0 && spec->lalign == 1)
	{
		spec->filler = ' ';
		output = spec->width - spec->prec_size;
		if (spec->prec_size < n_len)
			output = spec->width - n_len;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
}

void	get_u_int(va_list args, t_specs *spec)
{
	unsigned int	n;
	char			*number;
	int				n_len;

	n = va_arg(args, unsigned int);
	number = ft_utoa(n);
	n_len = ft_strlen(number);
	if (n == 0)
	{
		number = "0";
		n_len = 1;
	}
	u_right_align_fill(n, n_len, spec);
	if (n > 0 || (n == 0 && (spec->precision == 0 || spec->prec_size > 0)))
		ft_putnbr(number, n_len, spec);
	u_left_align_fill(n, n_len, spec);
}
