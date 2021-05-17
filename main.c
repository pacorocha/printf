#include <ft_printf.h>

void main()
{
printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, INT_MAX, 21, INT_MIN);
printf("\n");
ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, INT_MAX, 21, INT_MIN);
printf("\n");
}