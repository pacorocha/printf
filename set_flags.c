/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:03:48 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/17 13:43:56 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	format_minus(int i, t_specs *spec)
{
	if (spec->start_format == 1)
	{
		spec->lalign = 1;
		spec->minus = 1;
		i++;
	}
	return (i);
}

static int	parse_flag(const char *str, int i, t_specs *spec)
{
	spec->precision = 0;
	if (str[i] == '0' && spec->start_format == 1)
	{
		if (spec->minus == 0)
			spec->filler = '0';
		i++;
	}
	else
		spec->filler = ' ';
	i = define_number(str, i, spec);
	return (i);
}

static int	parse_wildcard(int i, va_list args, t_specs *spec)
{
	if (spec->is_width == 1)
		spec->width = get_wildcard_value(args, spec);
	if (spec->precision == 1)
		spec->prec_size = get_wildcard_value(args, spec);
	i++;
	return (i);
}

static int	parse_dot(const char *str, int i, t_specs *spec)
{
	i++;
	spec->precision = 1;
	if (ft_isdigit(str[i]))
		i = define_number(str, i, spec);
	else
		spec->prec_size = 0;
	return (i);
}

int	set_flags(const char *str, int i, va_list args, t_specs *spec)
{
	if (str[i] == '-')
		i = format_minus(i, spec);
	if (ft_isdigit(str[i]))
		i = parse_flag(str, i, spec);
	if (str[i] == '-')
		i = format_minus(i, spec);
	if (ft_isdigit(str[i]))
		i = parse_flag(str, i, spec);
	if (str[i] == '*')
	{
		spec->is_width = 1;
		i = parse_wildcard(i, args, spec);
	}
	if (str[i] == '.')
		i = parse_dot(str, i, spec);
	if (str[i] == '*')
	{
		spec->is_width = 0;
		i = parse_wildcard(i, args, spec);
	}
	if (str[i] == '\0')
		i--;
	return (i);
}
