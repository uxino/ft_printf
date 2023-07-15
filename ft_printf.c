/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:19:14 by museker           #+#    #+#             */
/*   Updated: 2023/07/15 13:41:37 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	type(char c, va_list list)
{
	int	len;

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
		len += ft_putunbr(va_arg(list, unsigned int)); 
	else if (c == 'x')
		len += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		len += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF", 16);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += type(str[i + 1], list);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(list);
	return (len);
}
