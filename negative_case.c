/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:02:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/17 12:00:07 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	fill_before_minus(int n_len, t_specs *spec)
{
	int	output;

	output = 0;
	if (spec->width >= 0 && spec->lalign == 0 && spec->filler == ' ')
	{
		if (spec->width > n_len)
			output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size - 1;
		print_fill(output, spec);
	}
	if (spec->width >= 0 && spec->precision == 1 && spec->filler == '0')
	{
		spec->filler = ' ';
		if (spec->prec_size > n_len)
			output = spec->width - spec->prec_size - 1;
		else
			output = spec->width - n_len;
		print_fill(output, spec);
	}
}

void	negative_case(int n, t_specs *spec)
{
	int	n_len;
	int	output;

	n = be_positive(n);
	n_len = num_size(n) + 1;
	fill_before_minus(n_len, spec);
	write(1, "-", 1);
	spec->total_chars++;
	if (spec->width >= 0 && spec->filler == '0' && spec->precision == 0
		&& spec->lalign == 0)
	{
		output = spec->width - n_len;
		print_fill(output, spec);
	}
	if (spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		if (spec->prec_size < n_len)
			output = 0;
		else
			output = spec->prec_size - n_len + 1;
		print_fill(output, spec);
	}
}
