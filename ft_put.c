/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:19:18 by museker           #+#    #+#             */
/*   Updated: 2023/07/15 15:38:48 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

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
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int		len;

	len = 0;
	if (n < 10)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putunbr(n / 10);
		len += ft_putchar(n % 10 + '0');
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

int	ft_puthex(unsigned long nbr, char *p, unsigned int a)
{
	int	count;

	count = 0;
	if (nbr >= a)
		count += ft_puthex(nbr / a, p, a);
	ft_putchar(p[nbr % a]);
	return (count + 1);
}

int	ft_putpointer(void *p)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)p, "0123456789abcdef", 16);
	return (len);
}
