/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:07:35 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/23 23:12:28 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_char(int i, va_list args, t_specs spec)
{
	char	c;
	int		j;

	c = va_arg(args, int);
	j = spec.width;
	while (j > 1)
	{
		ft_putchar(' ');
		j--;
		i++;
	}
	ft_putchar(c);
}
