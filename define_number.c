/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:48:06 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/10 00:22:22 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	define_number(const char *str, int i, t_specs *spec)
{
	int		j;
	char	*number_str;
	int		number;

	j = 1;
	number_str = ft_calloc(j, sizeof(int));
	while (ft_isdigit(str[i]))
	{
		number_str[j - 1] = str[i];
		j++;
		i++;
	}
	number_str[j] = '\0';
	number = ft_atoi(number_str);
	if (spec->precision == 0)
		spec->width = number;
	if (spec->precision == 1)
	{
		spec->prec_size = number;
		spec->prec_set = 1;
	}
	free(number_str);
	return (i);
}
