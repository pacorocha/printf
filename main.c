#include <ft_printf.h>

int main ()
{
	static char	a01;
	printf("%u", 4294967295u);
	printf("\n");
	ft_printf("%u", 4294967295u);
	printf("\n");
	return (0);
}