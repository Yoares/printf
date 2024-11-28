/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:45:42 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/26 17:59:18 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa(unsigned long num)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_puthexa(num / 16);
	count += ft_putchar(hex[num % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	i += write(1, "0x", 2);
	i += ft_puthexa((unsigned long)ptr);
	return (i);
}
