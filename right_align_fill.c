/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_align_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:10:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/06 17:11:08 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	right_align_fill(int n, int n_len, t_specs *spec)
{
	int output;

	if (n >= 0 && spec->width >= 0 && spec->lalign == 0)
	{
		if (spec->precision == 0 && spec->filler == '0')
			spec->filler = '0';
		else
			spec->filler = ' ';
		output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (n >= 0 && spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		output = spec->prec_size - n_len;
		print_fill(output, spec);
	}
}
