/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:46:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/17 13:56:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putnbr(char *number, int n_len, t_specs *spec)
{
	int output;
	ft_putstr(number);
	output = ft_strlen(number);
	n_len++;
	n_len--;
	spec->total_chars = spec->total_chars + output;
}
