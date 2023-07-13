#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *str)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return(count);
}


int ft_putunbr(unsigned int n)
{
	char	c;
	long 	len;

	len = 0;
	if (n < 10)
	{
		c = n + '0';
		len += ft_putchar(c);
	}
	else
	{
		ft_putunbr(n / 10);
		c = (n % 10) + '0';
		len += ft_putchar(c);
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

int ft_puthex(unsigned long nbr, char *p, unsigned int a)
{
    if (a == 16)
	{
    	if (nbr >= 16)
        	ft_puthex(nbr / 16, p, 16);
    	ft_putchar(p[nbr % 16]);
	}
	else if (a == 10)
	{
    	if (nbr >= 0)
        	ft_puthex(nbr / 10, p, 10);
    	ft_putchar(p[nbr % 10]);
	}
	return (1);
}

int ft_putpointer(void *p)
{
	int len;
	// char *p = "b";
	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)p,"0123456789abcdef", 16);
	return (len);
}
