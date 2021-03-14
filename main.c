/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:25:55 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/14 17:41:37 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	char c = 'c';
	char a = 'a';
	printf("printf: This is a print character test: %c and %c\n", c, a);
	ft_printf("ft_printf: This is a print character test: %c and %c\n\n", c, a);

	char *str = "String made of characters.";
	char *str2 = "Another string alsmo made of characters."
	printf("printf: This is a string: %s\n", str);
	ft_printf("ft_printf: This is a string: %s\n", str);
	printf("printf: These are two strings: %s\n", str, str2);
	ft_printf("ft_printf: These are two strings: %s\n", str, str2);

	void *pa = &c;
	printf("printf: This is a pointer address: %p\n", pa);

	int d = 120;
	printf("printf: This is a decimal: %d\n", d);

	int i = -456;
	printf("printf: This is an integer: %i\n", i);

	unsigned int ui = 345121;
	printf("printf: This is an unsigned integer: %u\n", ui);

	unsigned int h = 0xff00ff;
	printf("printf: This is an unsigned hexadecimal lowercase: %x\n", h);
	printf("printf: This is an unsigned hexadecimal uppercase: %X\n", h);

	printf("printf: This is just the character %%\n");

	return (0);
}
