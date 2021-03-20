/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:57:58 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/20 20:01:52 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			get_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
}

static void			get_string(va_list args)
{
	char	*arg_str;

	arg_str = va_arg(args, char *);
	ft_putstr(arg_str);
}

static int			get_hex(char c, va_list args)
{
	unsigned int	x;
	char			buf[sizeof(x) * 2];
	size_t			j;
	char			*hex;

	j = 0;
	x = va_arg(args, unsigned int);
	hex = "0123456789abcdef";
	if (!x)
		return (write(1, "(nil)", 5));
	if (c == 'p')
	{
		write(1, "0x", 2);
	}
	if (c == 'X')
		hex = "0123456789ABCDEF";
	while (j < sizeof(x) * 2)
	{
		buf[j] = hex[(x >> ((sizeof(x) * 2 - 1 - j) * 4)) & 0xf];
		j++;
	}
	return (write(1, buf, sizeof(buf)));
}

static void			get_integer(va_list args)
{
	int		n;
	char	*number;

	n = va_arg(args, int);
	number = ft_itoa(n);
	ft_putstr(number);
}

void				check_params(const char *str, int i, va_list args)
{
	if (str[i] == 'c')
		get_char(args);
	if (str[i] == 's')
		get_string(args);
	if (str[i] == 'p')
		get_hex(str[i], args);
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		get_integer(args);
	if (str[i] == 'x' || str[i] == 'X')
		get_hex(str[i], args);
}
