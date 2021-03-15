/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/14 19:28:43 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			get_char(char str, va_list args)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
}

int			get_string(char str, va_list args)
{
	char	*arg_str;
	arg_str = va_arg(args, char *);
	ft_putstr(arg_str);
}

int get_pointer(char str, va_list args) {
	unsigned int x = va_arg(args, unsigned int);
	write(1, &str, 12);
}

static int	ft_parse_str(const char *str, va_list args)
{
	static int	i;
	char		*arg_str;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				get_char(str[i], args);
				i++;
			}
			if (str[i] == 's')
			{
				get_string(str[i], args);
				i++;
			}
			if (str[i] == 'p')
			{
				get_pointer(str[i], args);
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
