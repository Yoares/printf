/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:06:34 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/25 13:06:34 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
