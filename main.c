#include <ft_printf.h>

int main()
{
	printf("printf: %p %p \n", 0x16e6b27ff, (void*)LONG_MAX);
	ft_printf("ft_printf: %p %p \n", 0x16e6b27ff, (void*)LONG_MAX);
	printf("printf: %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);
	ft_printf("ft_printf: %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);
}