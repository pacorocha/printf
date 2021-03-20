/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/20 19:58:22 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int		ft_parse_str(const char *str, va_list args)
{
	static int	i;
	char		*params;

	i = 0;
	params = "cspdiuxX";
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr(params, str[i]))
			{
				check_params(str, i, args);
				i++;
			}
		}
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int				ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	ft_parse_str(str, args);
	va_end(args);
	return (0);
}
