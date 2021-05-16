#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, LONG_MAX, 21, LONG_MIN);
	printf("\n");
	ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, LONG_MAX, 21, LONG_MIN);
	printf("\n");
	return (0);
}