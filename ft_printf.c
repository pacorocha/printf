/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:42:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/12 20:26:47 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		new_format(t_specs *spec)
{
	spec->total_chars = 0;
	spec->start_format = 0;
	spec->flags = "-*.";
	spec->params = "cspdiuxX%";
}

static void 	init_format(t_specs *spec)
{
	spec->start_format = 1;
	spec->width = 0;
	spec->prec_size = 0;
	spec->lalign = 0;
	spec->minus = 0;
	spec->precision = 0;
}

static void		reset_format(t_specs *spec)
{
	spec->width = 0;
	spec->prec_size = 0;
	spec->lalign = 0;
	spec->minus = 0;
	spec->precision = 0;
}

static int		set_format(const char *str, int i, va_list args, t_specs *spec)
{
	init_format(spec);
	i++;
	if (ft_strchr(spec->flags, str[i]) || ft_isdigit(str[i]))
		i = check_flags(str, i, args, spec);
	if (ft_strchr(spec->params, str[i]))
	{
		check_params(str[i], args, spec);
		reset_format(spec);
	}
	if (spec->width != 0)
	{
		print_fill(0, spec);
	}
	i++;
	return (i);
}

static int		ft_parse_str(const char *str, va_list args)
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

int				ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, str);
	printed_chars = ft_parse_str(str, args);
	va_end(args);
	return (printed_chars);
}
