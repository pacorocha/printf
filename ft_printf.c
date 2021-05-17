/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 21:35:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	new_format(t_specs *spec)
{
	spec->total_chars = 0;
	spec->start_format = 0;
	spec->flags = "-*.";
	spec->params = "cspdiuxX%";
}

static int	ft_parse_str(const char *str, va_list args)
{
	t_specs	spec;
	int		i;

	i = 0;
	new_format(&spec);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && spec.start_format == 0)
			i = set_format(str, i, args, &spec);
		else
		{
			ft_putchar(str[i]);
			i++;
			spec.total_chars++;
		}
	}
	return (spec.total_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, str);
	printed_chars = ft_parse_str(str, args);
	va_end(args);
	return (printed_chars);
}
