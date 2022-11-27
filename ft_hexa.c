/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.C                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:21:29 by marvin            #+#    #+#             */
/*   Updated: 2022/11/25 20:21:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_hex_len(unsigned long long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int ft_hexa(unsigned long long int n, char *s)
{
    if (n / 16)
       ft_hexa(n / 16, s);
    ft_putchar(s[n % 16]);
    return (ft_hex_len(n));
}

int print_pointer(unsigned long long int n, char *base)
{
    if (n == 0)
		return (ft_putchar('0'));
	else
		ft_hexa(n, base);
	return (ft_hex_len(n));
}