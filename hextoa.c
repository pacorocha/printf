/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:45:35 by jfrancis          #+#    #+#             */
/*   Updated: 2021/06/06 19:06:13 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*hextoa(unsigned long int x, char c, t_specs *spec)
{
	char	*hex;
	size_t	n_len;

	n_len = hex_size(x);
	hex = (char *)malloc(sizeof(char) * n_len + 1);
	hex[n_len] = '\0';
	while (n_len--)
	{
		if (x % 16 >= 10 && c == 'X')
			hex[n_len] = (x % 16) - 10 + 'A';
		else if (x % 16 >= 10)
			hex[n_len] = (x % 16) - 10 + 'a';
		else
			hex[n_len] = (x % 16) + '0';
		spec->total_chars++;
		x /= 16;
	}
	return (hex);
}
