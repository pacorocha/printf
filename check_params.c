/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:57:58 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/17 14:05:01 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	check_params(char c, va_list args, t_specs *spec)
{
	if (c == 'c' || c == '%')
		get_char(c, args, spec);
	if (c == 's')
	{
		get_string(args, spec);
		spec->filler = ' ';
	}
	if (c == 'p')
		get_pointer(args, spec);
	if (c == 'x' || c == 'X')
		get_hex(c, args, spec);
	if (c == 'd' || c == 'i')
		get_integer(args, spec);
	if (c == 'u')
		get_u_int(args, spec);
	spec->start_format = 0;
}
