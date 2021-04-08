/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/06 19:49:26 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_putnbr(char *number, int n_len, t_specs *spec)
{
	ft_putstr(number);
	spec->total_chars += n_len;
}

void		get_integer(va_list args, t_specs *spec)
{
	int		n;
	char	*number;
	int		n_len;
	int		output;

	n = va_arg(args, int);
	number = ft_itoa(n);
	n_len = num_size(n);
	if (n == 0 && !spec->prec_size)
		number = " ";
	output = spec->width - n_len;
	if (n > 0 && spec->filler == '0')
		print_fill(output, spec);
	if (spec->width > 0 && spec->filler == ' ')
	{
		if (n < 0)
			output--;
		print_fill(output, spec);
	}
	if (n < 0 && spec->width > 0 && spec->prec_size > 0 && spec->filler == '0')
	{
		negative_case(n, spec);
		number = ft_substr(number, 1, n_len);
	}
	ft_putnbr(number, n_len, spec);
}
