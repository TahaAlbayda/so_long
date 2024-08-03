/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:45:41 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/07/18 10:58:05 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(char c, va_list ptr)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += putlnbr(va_arg(ptr, int));
	if (c == 'c')
		len += putlchr(va_arg(ptr, int));
	if (c == 's')
		len += putlstr(va_arg(ptr, char *));
	if (c == 'u')
		len += putlunbr(va_arg(ptr, unsigned int));
	if (c == 'p')
		len += putlptr(va_arg(ptr, void *));
	if (c == 'x' || c == 'X')
		len += putlhex(c, va_arg(ptr, unsigned int));
	if (c == '%')
		len += putlchr(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += check_char(*(format + 1), ptr);
			format++;
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(ptr);
	return (len);
}
