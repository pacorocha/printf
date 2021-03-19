/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/19 18:52:46 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void			get_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
}

void			get_string(va_list args)
{
	char	*arg_str;
	arg_str = va_arg(args, char *);
	ft_putstr(arg_str);
}

int		get_pointer(va_list args) {
	unsigned int x;
    char buf[2 + sizeof(x) * 2];
    size_t i;
	char *hex;

	i = 0;
	x = va_arg(args, unsigned int);
    buf[0] = '0';
    buf[1] = 'x';
	hex = "0123456789abcdef";
	if (!x)
		return write(1, "(nil)", 5);
    while (i < sizeof(x) * 2) {
        buf[i + 2] = hex[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
		i++;
    }
    return write(1, buf, sizeof(buf));
}

void get_integer(va_list args)
{
	int n;
	char *number;

	n = va_arg(args, int);
	number = ft_itoa(n);

	ft_putstr(number);
}

static int	ft_parse_str(const char *str, va_list args)
{
	static int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				get_char(args);
				i++;
			}
			if (str[i] == 's')
			{
				get_string(args);
				i++;
			}
			if (str[i] == 'p')
			{
				get_pointer(args);
				i++;
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				get_integer(args);
				i++;
			}
		}
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	ft_parse_str(str, args);
	va_end(args);
	return (0);
}
