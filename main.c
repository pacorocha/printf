#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf("|%-5.0i|", 0);
	printf("\n");
	ft_printf("|%-5.0i|", 0);
	printf("\n");
	return (0);
}