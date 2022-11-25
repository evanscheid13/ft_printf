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

int ft_hexa(unsigned int n, char c)
{
    char *m;
    char *t;
    char *s;

    t = "0123456789abcdef";
    m = "0123456789ABCDEF";
    if (c == 'x')
        s = t;
    else
        s = m;
    if (n < 16)
        ft_putchar(s[n]);
    else
    {
        ft_hexa(n / 16, c);
        ft_putchar(s[n % 16]);
    }
    return (ft_intlen(n, 16) - 1); 
}