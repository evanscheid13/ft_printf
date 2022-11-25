/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:44:01 by marvin            #+#    #+#             */
/*   Updated: 2022/11/25 19:44:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_is_arg(va_list *a, const char *s, int i, int j)
{
    t = 0;
    if (s[i + 1] == 'c')
        ft_putchar(va_arg(*a, int));
    else if (s[i + 1] == 's')
        t = ft_putstr(va_arg(*a, char *));
    else if (s[i + 1] == 'p')
    {
        ft_putstr("0x");
        t = ft_hexa(va_arg(*a, long) 'x') + 2;
    }
    else if (s[i + 1] == 'd' || s[i + 1] == 'i')
        ft_putnbrr(va_arg(*a, int), &t);
    else if (s[i + 1] == 'u')
        ft_unsign(va_arg(*a, unsigned int), &t);
    else if (s[i + 1] == 'x' || s[i + 1] == 'X')
        t = ft_hexa(va_arg(*a, long), s[i + 1]);
    else if (s[i + 1] == '%')
        ft_putchar('%');
    else
        ft_putchar(s[i + 1]);
    return (t);
}

int ft_printf(const char *s, ...)
{
    int i;
    int j;
    int k;
    va_list a;

    i = -1;
    j = 0;
    k = 0;
    va_start(a, s);
    while (s[++i])
    {
        if (s[i] == '%')
            k += ft_is_arg(&a, s, i++, j);
        else
            ft_putchar(s[i]);
        k++;
    }
    va_end(a);
    return (k);
}
