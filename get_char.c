/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:07:35 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/09 20:18:34 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	get_char(va_list args, t_specs *spec)
{
	char	c;
	int		output;

	c = va_arg(args, int);
	output = spec->width - 1;
	if (spec->lalign == 0)
		print_fill(output, spec);
	ft_putchar(c);
	spec->total_chars++;
	if (spec->lalign == 1)
		print_fill(output, spec);
}
