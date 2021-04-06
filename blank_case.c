/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:16:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/04 14:05:43 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	blank_case(t_specs *spec)
{
	char	*number;
	int		output;

	number = "";
	output = spec->width;
	print_fill(output, spec);
	ft_putstr(number);
}
