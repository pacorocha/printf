/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:02:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/30 21:10:56 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	negative_case(int n, int i, t_specs spec)
{
	int		n_len;
	int		output;
	char *number;

	n = be_positive(n);
	number = ft_itoa(n);
	n_len = num_size(n);
	spec.filler = ' ';
	output = spec.width - spec.prec_size - 1;
	print_fill(output, i, spec);
	write(1, "-", 1);
	spec.filler = '0';
	i++;
	output = spec.prec_size - n_len;
	print_fill(output, i, spec);
	n = -(n);
	ft_putstr(number);
}
