/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:40:38 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/26 19:44:01 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	print_fill(int output, int i, t_specs spec)
{
	while (output > 0)
	{
		ft_putchar(spec.filler);
		output--;
		i++;
	}
	i--;
	return (i);
}
