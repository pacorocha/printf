#include <ft_printf.h>

int main ()
{
	int pf;
	int ft;
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	pf = printf("Simple input test");
	printf("\n");
	ft = ft_printf"Simple input test");
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
	pf = printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	printf("\n");
	ft = ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	printf("\n");
	printf("pf: %i\nft: %i\n", pf, ft);
	pf = printf("%10c", '0');
	printf("\n");
	ft = ft_printf("%10c", '0');
	printf("\n");
	printf("pf: %i\nft: %i\n", pf, ft);
	return (0);
}
