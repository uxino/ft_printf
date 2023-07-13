#include "ft_printf.h"

int type(char c, va_list list)
{
    int len;
    
    len = 0;
    if (c == 'c') 
        len += ft_putchar(va_arg(list, int));
    else if (c == 's') 
        len += ft_putstr(va_arg(list, char *)); 
    else if (c == 'p')
        len += ft_putpointer(va_arg(list, void *));
    else if (c == 'd') 
        len += ft_putnbr(va_arg(list, int));
    else if (c == 'i') 
        len += ft_putunbr(va_arg(list, unsigned int));
    else if (c == 'u') 
		len += ft_puthex(va_arg(list, unsigned int),"0123456789",10); 
    else if (c == 'x')
        len += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef", 16);
    else if (c == 'X')
        len += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF", 16);
    else if (c == '%')
		len += ft_putchar('%');
    return (len);
}
// # • %c tek bir karakter yazdırır.
// # • %s bir karakter dizisi yazdırır.
// # • %p Void * pointer argümanını hexadecimal biçiminde yazdırır.
// # • %d 10 tabanında decimal sayı yazdırır.
// # • %i 10 tabanında tam sayı yazdırır.
// # • %u 10 tabanında işaretsiz decimal sayı yazdırır.
// # • %x hexadecimal sayıyı (16 tabanında küçük harfler ile yazdırır.
// # • %X hexadecimal sayıyı (16 tabanında) büyük harfler ile yazdırır.
// # • %% yüzde işareti yazdırır
 
int	ft_printf(const char *str, ...)
{
	va_list list;
    int len;
	int i;

    len = 0;
	i = 0;
	va_start(list, str);
	while(str[i])
	{
		if (str[i] == '%')
        {
            len += type(str[i + 1], list);
            i++;
        }
        else
		    len += ft_putchar(str[i]);
        i++;
	}
    va_end(list);
    return (len); // kaç karakter yazdırdığı return edilir printf'de (can taşar)
}



// int	arg_check(char c, va_list lst)
// {
// 	int	len;

// 	len = 0;
// 	if (c == 'c')
// 		len += ft_putchar(va_arg(lst, int));
// 	else if (c == 's')
// 		len += ft_putstr(va_arg(lst, char *));
// 	else if (c == 'd')
// 		len += ft_putnbr(va_arg(lst, int));
// 	return (len);
// }