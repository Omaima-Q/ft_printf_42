/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:49:17 by oqaroot           #+#    #+#             */
/*   Updated: 2024/08/04 13:26:54 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

int	ft_put_ptr(void *ptr)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	count += 2;
	count += ft_put_hex((uintptr_t)ptr, 0);
	return (count);
}

int	check_type(char input, va_list arg)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (input == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (input == 'p')
	{
		i += ft_putstr("0x");
		i += ft_put_hex(va_arg(arg, unsigned long long), 0);
	}
	else if (input == 'd' || input == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (input == 'u')
		i += ft_put_unsigned(va_arg(arg, unsigned int));
	else if (input == 'x')
		i += ft_put_hex(va_arg(arg, unsigned int), 0);
	else if (input == 'X')
		i += ft_put_hex(va_arg(arg, unsigned int), 1);
	else if (input == '%')
		i += (ft_putchar('%'));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, format);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			i += check_type(*format, args);
		}
		else
		{
			i = i + ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (i);
}
