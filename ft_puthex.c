/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:49:05 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/26 15:19:38 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, int uppercase)
{
	int		i;
	char	*hex;

	i = 0;
	if (uppercase)
	{
		hex = "0123456789ABCDEF";
	}
	else
		hex = "0123456789abcdef";
	if (num >= 16)
	{
		i += ft_puthex(num / 16, uppercase);
	}
	i += ft_putchar(hex[num % 16]);
	return (i);
}
