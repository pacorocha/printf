/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:25:55 by jfrancis          #+#    #+#             */
/*   Updated: 2021/04/07 20:02:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
	char empty = '\0';
	print_yellow();
	printf("################################################## Begin test ##################################################\n");
	print_green();
	printf("Test no parameters:\n");
	print_white();
	printf("printf: This is a no parameters test.\n\n");
	ft_printf("ft_printf: This is a no parameters test.\n\n");
	print_green();
	printf("Test c:\n");
	print_white();
	printf("printf: This is a print character test: %c and %c and empty: %c.\n\n", c, a, empty);
	ft_printf("ft_printf:");
	ft_printf("This is a print character test: %c and %c and empty: %c.\n\n", c, a, empty);
	print_green();
	printf("Test s:\n");
	print_white();
	char *str = "String made of characters.";
	char *str2 = "Another string also made of characters.";
	printf("printf: This is a string: %s\n\n", str);
	ft_printf("ft_printf: This is a string: %s\n\n", str);
	print_green();
	printf("Test 2 strings:\n");
	print_white();
	printf("printf: These are two strings: %s is the first. %s is the second.\n\n", str, str2);
	ft_printf("ft_printf: These are two strings: %s is the first. %s is the second.\n\n", str, str2);
	printf("Test empty string:\n");
	print_white();
	char *empty_str = "";
	printf("printf: These is an empty string: %s.\n\n", empty_str);
	ft_printf("ft_printf: These is an empty string: %s.\n\n", empty_str);
	print_green();
	printf("Test p:\n");
	print_white();
	void *pa = &c;
	printf("printf: This is a pointer address: %p\n", pa);
	ft_printf("ft_printf: This is a pointer address: %p\n\n", pa);
	printf("Test null pointer:\n");
	print_white();
	void *np = NULL;
	printf("printf: This is a null pointer: %p\n", np);
	ft_printf("ft_printf: This is a null pointer: %p\n\n", np);
	print_green();
	printf("Test d:\n");
	print_white();
	int d = 120;
	printf("printf: This is a decimal: %d\n", d);
	ft_printf("ft_printf: This is a decimal: %d\n\n", d);
	printf("Test smallest integer:\n");
	print_white();
	int s_int = INT_MIN;
	printf("printf: This is a decimal: %d\n", s_int);
	ft_printf("ft_printf: This is a decimal: %d\n\n", s_int);
	print_green();
	printf("Test i:\n");
	print_white();
	int i = -456;
	printf("printf: This is an integer: %i\n", i);
	ft_printf("ft_printf: This is an integer: %i\n\n", i);
	print_green();
	printf("Test u:\n");
	print_white();
	unsigned int ui = 345121;
	printf("printf: This is an unsigned integer: %u\n", ui);
	ft_printf("ft_printf: This is an unsigned integer: %u\n\n", ui);
	print_green();
	printf("Test x:\n");
	print_white();
	unsigned int h = 0xff00ff;
	printf("printf: This is an unsigned hexadecimal lowercase: %x\n", h);
	ft_printf("ft_printf: This is an unsigned hexadecimal lowercase: %x\n", h);
	print_green();
	printf("Test X:\n");
	print_white();
	printf("printf: This is an unsigned hexadecimal uppercase: %X\n", h);
	ft_printf("ft_printf: This is an unsigned hexadecimal uppercase: %X\n\n", h);
	print_green();
	printf("Test %%:\n");
	print_white();
	printf("printf: This is just the character %%\n");
	ft_printf("ft_printf: This is just the character %%\n");
	print_green();
	printf("Test all parameters in one string:\n");
	print_white();
	printf("printf: These are all the parameters in one print: %c, %s, %p, %d, %i, %u, %x, %X and %% in the middle of a string.\n", c, str, pa, d, i, ui, h, h);
	ft_printf("ft_printf: These are all the parameters in one print: %c, %s, %p, %d, %i, %u, %x, %X and %% in the middle of a string.\n", c, str, pa, d, i, ui, h, h);

	print_yellow();
	printf("\n################################################## char ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%c|\n", '0');
	 printf("___printf: |%c|\n", '0');
	 ft_printf("ft_printf: |%10c|\n", '0');
	 printf("___printf: |%10c|\n", '0');
	 ft_printf("ft_printf: |%-10c|\n", '0');
	 printf("___printf: |%-10c|\n", '0');
	 ft_printf("ft_printf: |%*c|\n", 1, '0');
	 printf("___printf: |%*c|\n", 1,'0');
	 ft_printf("ft_printf: |%*c|\n", 0, '0');
	 printf("___printf: |%*c|\n", 0,'0');
	 ft_printf("ft_printf: |%*c|\n", 2, '0');
	 printf("___printf: |%*c|\n", 2,'0');
	 ft_printf("ft_printf: |%*c|\n", -2, '0');
	 printf("___printf: |%*c|\n", -2,'0');
	 ft_printf("ft_printf: |%*c|\n", 0, '0');
	 printf("___printf: |%*c|\n", 0,'0');
	 ft_printf("ft_printf: |%*c|\n", 10, '0');
	 printf("___printf: |%*c|\n", 10,'0');
	 ft_printf("ft_printf: |%*c|\n", -10, '0');
	 printf("___printf: |%*c|\n", -10,'0');
	 ft_printf("ft_printf: |%*c%*c|\n", -10, '0', 10, '1');
	 printf("___printf: |%*c%*c|\n", -10, '0', 10, '1');
	 ft_printf("ft_printf: |%c|\n", 'x');
	 printf("___printf: |%c|\n", 'x');
	 ft_printf("ft_printf: |%34c|\n", 'x');
	 printf("___printf: |%34c|\n", 'x');
	 ft_printf("ft_printf: |%c|\n", -129);
	 printf("___printf: |%c|\n", -129);
	print_yellow();
	printf("\n################################################## string ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%s|\n", "");
	 printf("___printf: |%s|\n", "");
	 ft_printf("ft_printf: |%2.s|\n", "42");
	 printf("___printf: |%2.s|\n", "42");
	 ft_printf("ft_printf: |%s|\n", "nariz");
	 printf("___printf: |%s|\n", "nariz");
	 ft_printf("ft_printf: |%3.7s|%7.7s|\n", "hello", "world");
	 printf("___printf: |%3.7s|%7.7s|\n", "hello", "world");
	 ft_printf("ft_printf: |%-10s|\n", "uepa");
	 printf("___printf: |%-10s|\n", "uepa");
	 ft_printf("ft_printf: |%7.7s|%4.3s|\n", "hello", "world");
	 printf("___printf: |%7.7s|%4.3s|\n", "hello", "world");
	 ft_printf("ft_printf: |%23s|\n", NULL);
	 printf("___printf: |%23s|\n", NULL);
	 ft_printf("ft_printf: |%.*s|\n", -5, "42");
	 printf("___printf: |%.*s|\n", -5, "42");
	 ft_printf("ft_printf:  --- Return : %d\n",  printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	 printf("___printf:  --- Return : %d\n", printf("|%-2s|\n|%.s|\n|%-4s|\n|%-2.4s|\n|%-8.12s|\n|%3s|\n|%8s|\n|%---2s|\n|%.*s|\n|%.0s|\n|%.1s|\n|%.2s|\n|%.4s|\n|%.8s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	print_yellow();
	printf("\n################################################## integer ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%3.0d|\n", 10);
	 printf("___printf: |%3.0d|\n", 10);
	 ft_printf("ft_printf:  --- Return : %d\n",  ft_printf("(null)"));
	 printf("___printf:  --- Return : %d\n", printf("(null)"));
	 ft_printf("ft_printf:  --- Return : %d\n",  ft_printf(""));
	 printf("___printf:  --- Return : %d\n", printf(""));
	 ft_printf("ft_printf: |%05.*d|\n", -15, 42);
	 printf("___printf: |%05.*d|\n", -15, 42);

	 ft_printf("ft_printf: |%8.3i|\n", 8375);
	 printf("___printf: |%8.3i|\n", 8375);
	 ft_printf("ft_printf: |%4i|\n", -14);
	 printf("___printf: |%4i|\n", -14);
	 ft_printf("ft_printf: |%5.i|\n", 0);
	 printf("___printf: |%5.i|\n", 0);
	 ft_printf("ft_printf: |%010.5i|\n", -216);
	 printf("___printf: |%010.5i|\n", -216);

	 ft_printf("ft_printf: |%.0u|\n", 10);
	 printf("___printf: |%.0u|\n", 10);

	/*
	** 	hex:
	*/
	print_yellow();
	printf("\n################################################## hex ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%.0x|\n", 100);
	 printf("___printf: |%.0x|\n", 100);
	 ft_printf("ft_printf: |%.x|\n", 0);
	 printf("___printf: |%.x|\n", 0);
	 ft_printf("ft_printf: |%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);
	 printf("___printf: |%*.*x| |%*.*X|\n", 1, 50, 5000, 1, 0, 10);

	/*
	** 	pointer:
	*/
	print_yellow();
	printf("\n################################################## pointer ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%1.p|\n", NULL);
	 printf("___printf: |%1.p|\n", NULL);
	 ft_printf("ft_printf: |%5.p|\n", NULL);
	 printf("___printf: |%5.p|\n", NULL);

	 ft_printf("ft_printf: |%026.51%|\n");
	 printf("___printf: |%026.51%|\n");


	print_yellow();
	printf("\n################################################## undefined behavior ##################################################\n\n");
	print_white();
	 ft_printf("ft_printf: |%09s|\n", "lala la");
	printf("___printf: |%09s|\n", "lala la");
	 ft_printf("ft_printf: |%-09s|\n", "lala la");
	printf("___printf: |%-09s|\n", "lala la");
	 ft_printf("ft_printf: |%2.9p|\n", 1234);
	printf("___printf: |%2.9p|\n", 1234);
	 ft_printf("ft_printf: |%*-c|\n", 3, 'x');
	printf("___printf: |%*-c|\n", 3, 'x');
	 ft_printf("ft_printf: |%-*c|\n", 3, 'x');
	printf("___printf: |%-*c|\n", 3, 'x');

	return (0);
}
