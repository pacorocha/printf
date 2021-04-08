/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:15:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/08 17:09:20 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	prefix_hex(char c, int x, t_specs *spec)
{
	if (c == 'p')
	{
		if (!x)
		{
			write(1, "0x0", 3);
			spec->total_chars = spec->total_chars + 3;
		}
		else
		{
			write(1, "0x", 2);
			spec->total_chars = spec->total_chars + 2;
		}
	}
}

static char	*gen_hex(char *hex, int i, unsigned int x, char c)
{
	while (x != 0)
	{
		if (x % 16 >= 10 && c == 'X')
			hex[i] = (x % 16) - 10 + 'A';
		else if (x % 16 >= 10)
			hex[i] = (x % 16) - 10 + 'a';
		else
			hex[i] = (x % 16) + '0';
		x /= 16;
		i++;
	}
	hex[i] = '\0';
	return (hex);
}

static void	reverse_output(char c, char *hex, int j, t_specs *spec)
{
	while (j > 0)
	{
		if (c == 'X')
			ft_putchar(ft_toupper(hex[j]));
		else
			ft_putchar(hex[j]);
		j--;
		spec->total_chars++;
	}
	spec->total_chars++;
}

void		get_hex(char c, va_list args, t_specs *spec)
{
	unsigned int	x;
	char			*hex;
	int				i;
	int				n_len;

	x = va_arg(args, unsigned int);
	i = 1;
	if (c != 'p')
		i = 2;
	n_len = num_size(x);
	hex = "";
	prefix_hex(c, x, spec);
	hex = ft_calloc(sizeof(x), (n_len + 1));
	hex = gen_hex(hex, i, x, c);
	if (spec->precision == 1 && spec->prec_size > n_len)
	{
		spec->filler = '0';
		print_fill(spec->prec_size - n_len, spec);
	}
	reverse_output(c, hex, n_len + i, spec);
	free(hex);
}
