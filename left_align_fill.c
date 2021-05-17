/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_align_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:13:31 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 21:31:29 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	left_align_fill(int n, int n_len, t_specs *spec)
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
			output = spec->width - n_len - 1;
		if (spec->prec_size > n_len)
			output = spec->width - spec->prec_size - 1;
		print_fill(output, spec);
	}
}
