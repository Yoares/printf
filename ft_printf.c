/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:05:53 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/24 21:05:53 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char s, va_list args)
{
	if (s == '%')
		return (ft_putchar('%'));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (s == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (s == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (s == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else
		return (ft_putchar('%') + ft_putchar(s));
	return (0);
}

static int	format_helper(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (1);
			i += 2;
		}
		else
			i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		c;
	va_list	args;

	c = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	if (format_helper(format))
		return (-1);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c += ft_format(format[i], args);
		}
		else
			c += (ft_putchar(format[i]));
		i++;
	}
	va_end(args);
	return (c);
}
