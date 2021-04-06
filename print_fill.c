/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:40:38 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/04 13:41:05 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_fill(int output, t_specs *spec)
{
	while (output > 0)
	{
		ft_putchar(spec->filler);
		output--;
		spec->total_chars++;
	}
	return (spec->total_chars);
}
