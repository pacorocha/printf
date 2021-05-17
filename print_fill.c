/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:40:38 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/17 14:10:22 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_fill(int output, t_specs *spec)
{
	char	c;
	int		i;

	c = spec->filler;
	i = 0;
	while (output > 0)
	{
		ft_putchar(c);
		output--;
		spec->total_chars++;
		i++;
	}
}
