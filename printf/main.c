#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	char c = 'a';
	char *p = "esad";
	printf("text%c%stext\n", c,p);
	ft_printf("text%c%stext", c,p);
	return 0;
}
