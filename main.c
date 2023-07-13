#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

// int main()
// {
// 	char c = 'a';
// 	char *p = "esad";
// 	printf("%p\n", p);
// 	ft_printf("%p", p);
// 	return 0;
// }

int main()
{

	char *p = "b";
	ft_putpointer(p);
	printf("      %lu",(unsigned long)p);

	return 0;
}

