/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/30 21:17:30 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		get_integer(int i, va_list args, t_specs spec)
{
	int		n;
	char	*number;
	int		n_len;
	int		output;

	n = va_arg(args, int);
	number = ft_itoa(n);
	n_len = num_size(n);
	if (n == 0 && !spec.prec_size)
		blank_case(i, spec);
	if (n < 0 && spec.width > 0 && spec.prec_size > 0 && spec.filler == '0')
		negative_case(n, i, spec);
	output = spec.width - n_len;
	if (n > 0 && spec.filler == '0')
	{
		print_fill(output, i, spec);
		ft_putstr(number);
	}
	if (n != 0 && spec.width > 0 && spec.filler == ' ')
	{
		if (n < 0)
			output--;
		print_fill(output, i, spec);
		ft_putstr(number);
	}
}
