/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/31 19:45:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void	prefix_hex(char c, int x)
{
	if (c == 'p')
	{
		if (!x)
			write(1, "(nil)", 5);
		else
			write(1, "0x", 2);
	}
}

static void	reverse_output(int i, char c, char *hex, int j)
{
	while (j + 1 > 0)
	{
		if (c == 'X')
			ft_putchar(ft_toupper(hex[j]));
		else
			ft_putchar(hex[j]);
		j--;
		i++;
	}
	ft_putchar('\0');
}

void		get_hex(int i, char c, va_list args)
{
	unsigned int	x;
	char			*hex;
	int				j;
	int				rem;

	x = va_arg(args, unsigned int);
	j = 0;
	hex = "";
	prefix_hex(c, x);
	if ((hex = (char*)malloc(sizeof(x) * 16 + 1)))
	{
		while (x != 0)
		{
			rem = x % 16;
			if (rem <= 9)
				hex[j] = rem + '0';
			else
				hex[j] = (rem - 10) + 'a';
			x = x / 16;
			j++;
		}
	}
	hex[j] = '\0';
	reverse_output(i, c, hex, j);
}
