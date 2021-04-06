/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:50:39 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/01 19:22:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
