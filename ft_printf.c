/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:48:39 by mregrag           #+#    #+#             */
/*   Updated: 2023/12/11 19:59:06 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (write(1, "c", 0) == -1)
		return (-1);
	if (!format)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
				len += print_format(*(++format), ap);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}
