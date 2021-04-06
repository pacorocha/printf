/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:57:58 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/04 17:52:43 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	check_params(char c, va_list args, t_specs *spec)
{
	if (c == 'c')
		get_char(args, spec);
	if (c == 's')
		get_string(args, spec);
	if (c == 'p')
		get_hex(c, args, spec);
	if (c == 'd' || c == 'i' || c == 'u')
		get_integer(args, spec);
	if (c == 'x' || c == 'X')
		get_hex(c, args, spec);
}
