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
	pf = printf("pf: |\\!/%32c\\!/|", 'H');
	printf("\n");
	ft = ft_printf("ft: |\\!/%32c\\!/|", 'H');
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();

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

	pf = printf("pf: |%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|", i, j, k, l, m, n, c, c, j, j, j);
	printf("\n");
	ft = ft_printf("ft: |%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X|", i, j, k, l, m, n, c, c, j, j, j);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	pf = printf("pf: |%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d|", i, j, k, l, m, c, e, d);
	printf("\n");
	ft = ft_printf("ft: |%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d|", i, j, k, l, m, c, e, d);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	pf = printf("pf: |%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d|", i, j, k, l, m, c, e, d);
	printf("\n");
	ft = ft_printf("ft: |%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d|", i, j, k, l, m, c, e, d);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	b = g;
	print_white();
	pf = printf("pf: |%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X|", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("\n");
	ft = ft_printf("ft: |%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X|", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	pf = printf("pf: |%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x|", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	printf("\n");
	ft = ft_printf("ft: |%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x|", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	pf = printf("pf: | --0*%-0*.20u*0 0*%-0*.10u*0-- |", -21, 54, 21, 47);
	printf("\n");
	ft = ft_printf("ft: | --0*%-0*.20u*0 0*%-0*.10u*0-- |", -21, 54, 21, 47);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	pf = printf("pf: |%010.0x|", UINT_MAX);
	printf("\n");
	ft = ft_printf("ft: |%010.0x|", UINT_MAX);
	printf("\n");
	print_green();
	printf("pf: %i\nft: %i\n", pf, ft);
	print_white();
	return (0);
}
