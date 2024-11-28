/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:45:21 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/24 20:45:21 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}
