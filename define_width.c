/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:27:31 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/09 21:14:37 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	define_width(int s_len, t_specs *spec)
{
	int output;

	if (spec->width > s_len && spec->prec_size < s_len)
		output = spec->prec_size - s_len;
	if (spec->width > s_len && spec->prec_size > s_len)
		output = spec->width - s_len;
	if (spec->width <= s_len && spec->prec_size < s_len)
		output = spec->width - spec->prec_size;
	if (spec->width > s_len && spec->prec_size == 0)
		output = spec->width - s_len;
	print_fill(output, spec);
}
