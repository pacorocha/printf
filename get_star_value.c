/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:06:24 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/04 19:08:34 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		get_star_value(va_list args, t_specs *spec)
{
	int	n;

	n = va_arg(args, int);
	if (n < 0)
	{
		spec->lalign = 1;
		n -= n * 2;
	}
	return (n);
}
