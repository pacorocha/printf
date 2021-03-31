/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:57:58 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/31 19:31:31 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_params(const char *str, int i, va_list args,
					t_specs spec)
{
	if (str[i] == 'c')
		get_char(i, args, spec);
	if (str[i] == 's')
		get_string(i, args, spec);
	if (str[i] == 'p')
		get_hex(i, str[i], args);
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		get_integer(i, args, spec);
	if (str[i] == 'x' || str[i] == 'X')
		get_hex(i, str[i], args);
}
