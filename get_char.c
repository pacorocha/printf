/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:07:35 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/09 17:55:49 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	get_char(char c, va_list args, t_specs *spec)
{
	char	k;
	int		output;

	if (c == '%')
		k = c;
	else
		k = va_arg(args, int);
	output = spec->width - 1;
	if (spec->lalign == 0)
		print_fill(output, spec);
	ft_putchar(k);
	spec->total_chars++;
	if (spec->lalign == 1)
		print_fill(output, spec);
}
