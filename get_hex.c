/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/05 18:46:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	prefix_hex(char c, int x)
{
	if (c == 'p')
	{
		if (!x)
			write(1, "0x0", 3);
		else
			write(1, "0x", 2);
	}
}

static void	reverse_output(char c, char *hex, int j)
{
	while (j + 1 > 0)
	{
		if (c == 'X')
			ft_putchar(ft_toupper(hex[j]));
		else
			ft_putchar(hex[j]);
		j--;
	}
	ft_putchar('\0');
}

void		get_hex(char c, va_list args, t_specs *spec)
{
	unsigned int	x;
	char			*hex;
	int				j;

	x = va_arg(args, unsigned int);
	j = 0;
	hex = "";
	prefix_hex(c, x);
			printf("hex %i", spec->width);
	reverse_output(c, hex, j);
}
