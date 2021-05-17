#include <ft_printf.h>

void main()
{
printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, UINT_MAX, 21, UINT_MIN);
printf("\n");
ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, UINT_MAX, 21, UINT_MIN);
printf("\n");
}