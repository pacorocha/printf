/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:02:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/25 22:42:21 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	negative_case(int n, t_specs *spec)
{
	int	n_len;
	int	output;

	n = be_positive(n);
	n_len = num_size(n) + 1;
	if ((spec->precision == 1 && spec->lalign == 0) || n == -2147483648)
	{
		spec->filler = ' ';
		if (spec->prec_size <= 0 )
			output = spec->width - spec->prec_size - n_len;
		if (spec->prec_size > 0 )
			output = spec->width - spec->prec_size - 1;
		print_fill(output, spec);
	}
	write(1, "-", 1);
	spec->filler = '0';
	spec->total_chars++;
	if (spec->prec_size > spec->width && spec->prec_size > n_len)
		output = spec->prec_size - n_len + 1;
	if (spec->width > spec->prec_size && spec->prec_size > n_len)
		output = spec->width - spec->prec_size - n_len;
	if (spec->width > spec->prec_size && spec->prec_size <= n_len)
		output = spec->width - spec->prec_size;
	if (spec->precision == 0)
		output = output - n_len;
	if (spec->prec_size == 0 && spec->precision == 1)
		output = 0;
	if (n > 2147483647)
		printf("pasó");
	if (spec->prec_size == n_len && spec->precision == 1)
		output = 1;
	if (n > -2147483648 && spec->lalign == 0 && spec->width >= spec->prec_size && spec->precision == 0)
		print_fill(output, spec);
	if (n > -2147483648 && spec->lalign == 0 && spec->precision == 1 && spec->prec_size >= n_len)
		print_fill(output, spec);
	if (output > 0 && spec->lalign == 1 && spec->prec_size >= n_len)
		print_fill(output, spec);
}
