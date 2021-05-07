#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf(" %*.5s %*.5s ", 10, "123", 10, "4567");
	printf("\n");
	ft_printf(" %*.5s %*.5s ", 10, "123", 10, "4567");
	printf("\n");
	printf("*%*.*i* ", 10, 21, -10);
	printf("\n");
	ft_printf("*%*.*i* ", 10, 21, -10);
	printf("\n");
	return (0);
}