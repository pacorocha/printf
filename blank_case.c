/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:16:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/31 17:12:30 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	blank_case(int i, t_specs spec)
{
	char	*number;
	int		output;

	number = "";
	output = spec.width;
	print_fill(output, i, spec);
	ft_putstr(number);
}
