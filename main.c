#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *str = "bonjour";
	void *p = malloc(5);

	int ret = 0;
	ret = ft_printf("%s\n", str);
	int ret2 = printf("%s\n", str);
	printf("{%d}..{%d}\n", ret, ret2);

	ret = ft_printf("%p\n", p);
	ret2 = printf("%p\n", p);
	printf("{%d}..{%d}\n", ret, ret2);
}
