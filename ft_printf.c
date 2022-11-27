/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:17:31 by evscheid          #+#    #+#             */
/*   Updated: 2022/11/26 14:17:31 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_is_arg(va_list a, const char *s, int i, int t)
{
    t = 0;
    if (s[i + 1] == 'c')
        return (ft_putchar(va_arg(a, int)));
    else if (s[i + 1] == 's')
        return (ft_putstr(va_arg(a, char *)));
    else if (s[i + 1] == 'p')
    {
        t += ft_putstr("0x");
        t += print_pointer(va_arg(a, unsigned long long int), "0123456789abcdef");
        return (t);
    }
    else if (s[i + 1] == 'd' || s[i + 1] == 'i') {
        // ft_putnbr_base(va_arg(a, int), "0123456789");
        return (handleint(va_arg(a, int), "0123456789"));
    }
    else if (s[i + 1] == 'u')
        return (handleint(va_arg(a, unsigned int), "0123456789"));
    else if (s[i + 1] == 'x')
        return (print_pointer(va_arg(a, unsigned long long int), "0123456789abcdef"));
    else if (s[i + 1] == 'X')
        return (print_pointer(va_arg(a, unsigned long long int), "0123456789ABCDEF"));
    else if (s[i + 1] == '%')
        return ft_putchar('%');
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
            k += ft_is_arg(a, s, i++, j);
        else
            k += ft_putchar(s[i]);
    }
    va_end(a);
    return (k);
}