/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:40:38 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/14 22:18:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_fill(int output, t_specs *spec)
{
	char	c;
	int		i;

	i = 0;
	if (spec->filler == '0')
		c = '0';
	else
		c = ' ';
	while (output > 0)
	{
		ft_putchar(c);
		output--;
		spec->total_chars++;
		i++;
	}
}
