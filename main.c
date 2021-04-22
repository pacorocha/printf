#include <ft_printf.h>

int main ()
{
	ft_printf(" *%*.*d* *%10.21d* ", -6, 2, 102, 101);
	ft_printf("\n");
	ft_printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101);
	return (0);
}