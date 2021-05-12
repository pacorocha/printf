/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:30:13 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/12 13:24:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		get_u_int(va_list args, t_specs *spec)
{
	unsigned int	n;
	char			*number;
	int				n_len;

	n = va_arg(args, unsigned int);
	number = ft_utoa(n);
	n_len = num_size(n);
	if (n == 0)
	{
		number = "0";
		n_len = 1;
	}
	right_align_fill(n, n_len, spec);
	if (n > 0 || (n == 0 && (spec->precision == 0 || spec->prec_size > 0)))
		ft_putnbr(number, n_len, spec);
	left_align_fill(n, n_len, spec);
}
