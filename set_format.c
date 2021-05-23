/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:34:15 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/16 11:50:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	init_format(t_specs *spec)
{
	spec->start_format = 1;
	spec->width = 0;
	spec->prec_size = 0;
	spec->lalign = 0;
	spec->minus = 0;
	spec->precision = 0;
}

static void	reset_format(t_specs *spec)
{
	spec->width = 0;
	spec->prec_size = 0;
	spec->lalign = 0;
	spec->minus = 0;
	spec->precision = 0;
}

int	set_format(const char *str, int i, va_list args, t_specs *spec)
{
	init_format(spec);
	i++;
	if (ft_strchr(spec->flags, str[i]) || ft_isdigit(str[i]))
		i = set_flags(str, i, args, spec);
	if (!ft_strchr(spec->params, str[i]))
		i--;
	if (ft_strchr(spec->params, str[i]))
	{
		check_params(str[i], args, spec);
		reset_format(spec);
	}
	i++;
	return (i);
}
