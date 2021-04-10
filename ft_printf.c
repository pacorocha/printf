/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/09 23:09:58 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				get_variable(va_list args, t_specs *spec)
{
	int		n;

	n = va_arg(args, int);
	if (n < 0)
	{
		spec->lalign = 1;
		n -= n*2;
	}
	return (n);
}

static int		ft_parse_str(const char *str, va_list args)
{
	char	*params;
	t_specs	spec;
	int		i;

	i = 0;
	spec.total_chars = 0;
	params = "cspdiuxX";
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			spec.width = 0;
			spec.precision = 0;
			spec.lalign = 0;
			i++;
			if (str[i] == '%')
			{
				ft_putchar('%');
				i++;
				spec.total_chars++;
			}
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
				spec.width = get_variable(args, &spec);
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
				if (spec.precision == 1)
					spec.prec_size = get_variable(args, &spec);
				i++;
			}
			if (ft_strchr(params, str[i]))
			{
				check_params(str[i], args, &spec);
				i++;
			}
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			spec.total_chars++;
		}
	}
	return (spec.total_chars);
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
