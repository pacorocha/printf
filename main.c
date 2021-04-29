#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf("%p", &a01);
	printf("\n");
	ft_printf("%p", &a1);
	printf("\n");
	return (0);
}