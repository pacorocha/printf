/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:19:51 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/03 22:22:48 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_putnbr(char *number, int n_len, t_specs *spec)
{
	ft_putstr(number);
	spec->total_chars += n_len;
}

static void	right_align_fill(int n, int n_len, t_specs *spec)
{
	int output;

	if (n >= 0 && spec->width >= 0 && spec->lalign == 0)
	{
		if (spec->precision == 0 && spec->filler == '0')
			spec->filler = '0';
		else
			spec->filler = ' ';
		output = spec->width - n_len;
		if (spec->precision == 1 && spec->prec_size > n_len)
			output = spec->width - spec->prec_size;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (n >= 0 && spec->prec_size >= 0 && spec->precision == 1)
	{
		spec->filler = '0';
		output = spec->prec_size - n_len;
		print_fill(output, spec);
	}
}

static void	left_align_fill(int n, int n_len, t_specs *spec)
{
	int output;

	if (n >= 0 && spec->width && spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len;
		else
			output = spec->width - spec->prec_size;
		if (n == 0 && spec->precision == 1 && spec->prec_size == 0)
			output++;
		print_fill(output, spec);
	}
	if (n < 0 && spec->lalign == 1)
	{
		spec->filler = ' ';
		if (spec->prec_size <= n_len)
			output = spec->width - n_len - 1;
		if (spec->prec_size > n_len)
			output = spec->width - spec->prec_size - 1;
		print_fill(output, spec);
	}
}

void		get_integer(va_list args, t_specs *spec)
{
	int		n;
	char	*number;
	int		n_len;

	n = va_arg(args, int);
	number = ft_itoa(n);
	n_len = num_size(n);
	if (n == 0)
	{
		number = "0";
		n_len = 1;
	}
	if (n < 0)
	{
		negative_case(n, spec);
		number = ft_substr(number, 1, n_len);
		ft_putnbr(number, n_len, spec);
		free(number);
	}
	right_align_fill(n, n_len, spec);
	if (n > 0 || (n == 0 && (spec->precision == 0 || spec->prec_size > 0)))
		ft_putnbr(number, n_len, spec);
	left_align_fill(n, n_len, spec);
}
