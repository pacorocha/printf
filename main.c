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

int main ()
{
	int pf;
	int ft;
	pf = printf("Simple input test");
	printf("\n");
	ft = ft_printf("Simple input test");
	printf("\n");
	pf = printf("printf: |%*.3d|", 6, 5);
	printf("\n");
	ft = ft_printf("ft_printf: |%*.3d|", 6, 5);
	printf("\n");
	printf("pf: %i\nft: %i\n", pf, ft);
	pf = printf("printf: |%*.d|", 5, -4);
	printf("\n");
	ft = ft_printf("ft_printf: |%*.d|", 5, -4);
	printf("\n");
	printf("pf: %i\nft: %i\n", pf, ft);
	printf("pf: %i\nft: %i\n", pf, ft);
	pf = printf("%10c", '0');
	printf("\n");
	ft = ft_printf("%10c", '0');
	printf("\n");
	printf("pf: %i\nft: %i\n", pf, ft);
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
	printf("printf: This is a print character test: %c and %c\n\n", c, a);
	printf("printf: This is a print character test: %c and %c and empty: %c.\n\n", c, a, empty);
	ft_printf("ft_printf:");
	ft_printf("This is a print character test: %c and %c\n\n", c, a);
	ft_printf("This is a print character test: %c and %c and empty: %c.\n\n", c, a, empty);
	print_green();
	printf("Test s:\n");
	print_white();
	char *str = "String made of characters.";
	char *str2 = "Another string also made of characters.";
	printf("pf: This is a string: %s\n\n", str);
	ft_printf("ft: This is a string: %s\n\n", str);
	printf("pf: These are two strings:\n%s is the first.\n%s is the second.\n\n", str, str2);
	ft_printf("ft: These are two strings:\n%s is the first.\n%s is the second.\n\n", str, str2);

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
	ft_printf("ft_printf: This is a pointer address: %p\n", pa);

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
	return (0);
}
