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
        len += ft_putnbr(va_arg(list, int));
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


// printf("%s%d%s",p)
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

// Errors found:
// For p format:
// Error in test 1: ft_printf("%p", ""): returned: 3, but expected: 11
// Error in test 3: ft_printf("%p", (void *)-14523): returned: 3, but expected: 18
// Error in test 4: ft_printf("0x%p-", (void *)ULONG_MAX): returned: 6, but expected: 21
// Error in test 5: ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void 
// *)INT_MAX): returned: 10, but expected: 32
// For x format:
// Error in test 2: ft_printf("%x", -10): returned: 1, but expected: 8
// Error in test 3: ft_printf("%x", -200000): returned: 1, but expected: 8
// Error in test 4: ft_printf("%x", -6000023): returned: 1, but expected: 8
// Error in test 6: ft_printf("%x", 10000): returned: 1, but expected: 4
// Error in test 7: ft_printf("%x", 100023): returned: 1, but expected: 5
// Error in test 8: ft_printf("%x", 0xabcdef): returned: 1, but expected: 6
// Error in test 9: ft_printf("%x", 0x7fedcba1): returned: 1, but expected: 8
// Error in test 10: ft_printf("%x", INT_MAX): returned: 1, but expected: 8
// Error in test 11: ft_printf("%x", INT_MIN): returned: 1, but expected: 8
// Error in test 12: ft_printf("%x", UINT_MAX): returned: 1, but expected: 8
// Error in test 14: ft_printf("%x%xx%x", 1, 2, -3): returned: 4, but expected: 11
// For X format:
// Error in test 2: ft_printf("%X", -10): returned: 1, but expected: 8
// Error in test 3: ft_printf("%X", -200000): returned: 1, but expected: 8
// 25:     TEST(1, print(" %p ", -1));
// 28:     TEST(4, print(" %p ", 16));
// 29:     TEST(5, print(" %p ", 17));
// 30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 31:     TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
// 32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 26:     TEST(2, print(" %x ", -1));
// 32:     TEST(8, print(" %x ", 16));
// 33:     TEST(9, print(" %x ", 17));
// 34:     TEST(10, print(" %x ", 99));
// 35:     TEST(11, print(" %x ", 100));
// 36:     TEST(12, print(" %x ", 101));
// 37:     TEST(13, print(" %x ", -9));
// 38:     TEST(14, print(" %x ", -10));
// 39:     TEST(15, print(" %x ", -11));
// 40:     TEST(16, print(" %x ", -14));
// 41:     TEST(17, print(" %x ", -15));
