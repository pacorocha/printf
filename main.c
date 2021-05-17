#include <ft_printf.h>

int main ()
{
	int pf;
	int ft;
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
	return (0);
}
