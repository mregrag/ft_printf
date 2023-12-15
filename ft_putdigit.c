/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:19:02 by mregrag           #+#    #+#             */
/*   Updated: 2023/12/11 18:11:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

static int	putaddress(unsigned long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar(symbols[n]));
	else
	{
		count = putaddress(n / 16);
		count += putaddress(n % 16);
		return (count);
	}
}

int	ft_putdigit(long n, int base, char format)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (format == 'p')
		return (putaddress(n) + 2);
	if (n < 0 && (format == 'd' || format == 'i'))
	{
		write(1, "-", 1);
		return (ft_putdigit(-n, base, format) + 1);
	}
	else if (n < base)
	{
		if (format == 'X')
			return (ft_putchar(toupper(symbols[n])));
		else
			return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_putdigit(n / base, base, format);
		count += ft_putdigit(n % base, base, format);
		return (count);
	}
}
