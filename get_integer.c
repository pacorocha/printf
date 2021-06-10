/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/09 21:41:29 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	get_integer(va_list args, t_specs *spec)
{
	int		n;
	char	*number;
	int		n_len;

	n = va_arg(args, int);
	number = ft_itoa(n);
	n_len = num_size(n);
	if (n == 0)
	{
		number = "0";
		n_len = 1;
	}
	if (n < 0)
	{
		negative_case(n, spec);
		number = ft_substr(number, 1, n_len);
		ft_putnbr(number, n_len, spec);
		free(number);
	}
	right_align_fill(n, n_len, spec);
	if (n > 0 || (n == 0 && (spec->precision == 0 || spec->prec_size > 0)))
		ft_putnbr(number, n_len, spec);
	left_align_fill(n, n_len, spec);
}
