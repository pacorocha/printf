#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf("printf: |%*.d)|", 5, -4);
	printf("\n");
	ft_printf("ft_printf: |%*.d|", 5, -4);
	printf("\n");
	return (0);
}
