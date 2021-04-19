/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:02:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/18 20:26:11 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	negative_case(int n, t_specs *spec)
{
	int	n_len;
	int	output;
	int	neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	n = be_positive(n);
	n_len = num_size(n);
	if(spec->width > spec->prec_size && spec->prec_size > n_len)
		spec->filler = ' ';
	if (neg == 1 && spec->width > spec->prec_size && spec->filler == ' ')
		print_fill((spec->width - spec->prec_size) - 1, spec);
	write(1, "-", 1);
	spec->filler = '0';
	spec->total_chars++;
	output = spec->prec_size - n_len;
	if(spec->width > spec->prec_size && spec->prec_size <= n_len && spec->lalign == 0)
		output = spec->width - n_len - 1;
	print_fill(output, spec);
}
