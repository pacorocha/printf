/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:25:55 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/14 20:41:35 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_blue()
{
	printf("\033[0;34m");
}

void print_green()
{
	printf("\033[0;32m");
}
void print_yellow()
{
	printf("\033[0;33m");
}
void print_white()
{
	printf("\033[0;37m");
}

int main()
{
	char c = '#';
	char a = 'a';
	print_yellow();
	printf("################################################## Begin test ##################################################\n");
	print_green();
	printf("Test c:\n");
	print_white();
	printf("printf: This is a print character test: %c and %c\n\n", c, a);
	ft_printf("ft_printf:");
	ft_printf("This is a print character test: %c and %c\n\n", c, a);
	print_green();
	printf("Test s:\n");
	print_white();
	char *str = "String made of characters.";
	char *str2 = "Another string also made of characters.";
	printf("printf: This is a string: %s\n\n", str);
	ft_printf("ft_printf: This is a string: %s\n\n", str);
	printf("printf: These are two strings:\n%s is the first.\n%s is the second.\n\n", str, str2);
	ft_printf("ft_printf: These are two strings:\n%s is the first.\n%s is the second.\n\n", str, str2);

	void *pa = &c;
	printf("printf: This is a pointer address: %p\n", pa);
	ft_printf("ft_printf: This is a pointer address: %p\n", pa);

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
