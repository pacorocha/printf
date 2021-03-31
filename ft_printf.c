/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/31 19:32:50 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				get_variable(va_list args)
{
	int		n;

	n = va_arg(args, int);
	if (n < 0)
		n = -n;
	return (n);
}

static int		ft_parse_str(const char *str, va_list args)
{
	char	*params;
	t_specs	spec;
	int		i;

	i = 0;
	spec.width = 0;
	spec.lalign = 0;
	params = "cspdiuxX";
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '-')
			{
				spec.lalign = 1;
				i++;
			}
			if (ft_isdigit(str[i]))
			{
				spec.precision = 0;
				if (str[i] == '0')
				{
					spec.filler = '0';
					i++;
				}
				else
					spec.filler = ' ';
				i = define_number(str, i, &spec);
			}
			if (str[i] == '*')
			{
				spec.width = get_variable(args);
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				spec.precision = 1;
				if (ft_isdigit(str[i]))
					i = define_number(str, i, &spec);
					else
						spec.prec_size = 0;
			}
			if (str[i] == '*')
			{
				spec.prec_size = get_variable(args);
				i++;
			}
			if (ft_strchr(params, str[i]))
			{
				check_params(str, i, args, spec);
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
	int printed_chars;
	va_start(args, str);
	printed_chars = ft_parse_str(str, args);
	va_end(args);
	return (printed_chars);
}
