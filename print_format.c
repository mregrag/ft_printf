/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:26:45 by mregrag           #+#    #+#             */
/*   Updated: 2023/12/12 09:00:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		len += ft_putdigit(va_arg(ap, int), 10, 'd');
	else if (format == 'x')
		len += ft_putdigit(va_arg(ap, unsigned int), 16, 'x');
	else if (format == 'X')
		len += ft_putdigit(va_arg(ap, unsigned int), 16, 'X');
	else if (format == 'u')
		len += ft_putdigit(va_arg(ap, unsigned int), 10, 'u');
	else if (format == 'p')
	{
		write(1, "0x", 2);
		len += ft_putdigit(va_arg(ap, unsigned long), 16, 'p');
	}
	else
		len += write(1, &format, 1);
	return (len);
}
