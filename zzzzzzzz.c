/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:22:49 by marvin            #+#    #+#             */
/*   Updated: 2022/11/25 16:22:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_sc
{
    int    len;
    int    width;
}               t_sc;

void   ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_printhexa(unsigned int n)
{
    char    *base;
    int     res[100];
    int     i;

    i = 0;
    base = "0123456789abcdef";
    while (n >= 16)
    {
        res[i] = base[n % 16];
        n = n / 16;
        i++;
    }
    res[i] = base[n];
    while (i >= 0)
    {
        ft_putchar(res[i]);
        i--;
    }
}

int    ft_strlen(const char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putnbr(int n)
{
    if (n == INT_MIN)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (n >= 0 && n <= 9)
        ft_putchar(n + '0');
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

int ft_intlen(int nb, char c)
{
    int i;
    int num;
    int neg;

    i = 0;
    if (!nb)
            return (1);
    if (nb < 0)
    {
        neg = 1;
        nb = -nb;
    }
    else
    {
        neg = 0;
        num = nb;
    }
    if (c == 'd')
    {
        while (num)
        {
            num /= 10;
            i++;
        }
    }
    if (c == 'x')
    {
        while (num)
        {
            num /= 16;
            i++;
        }
    }
}

char    *ft_strchr(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
            return ((char *)s);
        i++;
    }
    if (!s[i])
        return ((char *)s);
    return (NULL);
}

const char   *ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
    int i;

    i = 0;   
    if (format[i] == 'd')
    {
        int   d;
        d = va_arg(arg, int);
        ft_putnbr(d);
        sc -> len += ft_intlen(d, format[i]);
    }
    else if (format[i] == 's')
    {
        char *s;
        s = va_arg(arg, char *);
        if (!s)
        {
            write(1, "(null)", 6);
            sc -> len += 6;
        }
        else
        {
            ft_putstr(s);
            sc -> len += ft_strlen(s);
        }
    }
    else if (format[i] == 'x')
    {
        unsigned int   x;
        x = va_arg(arg, unsigned int);
        ft_printhexa((unsigned long)x);
        sc -> len += ft_intlen((unsigned long)x, format[i]);
    }
    else
        return (NULL);
    format += 1;
    return (format);
}

const char *ft_read_text(t_sc *sc, const char *format)
{
    char   *next;

    next = ft_strchr(format);
    if (next)
        sc -> len = next - format;
    else
        sc -> width = ft_strlen(format);
    write(1, format, sc -> width);
    sc -> len += sc -> width;
    while (*format && *format != '%')
        ++format;
    return (format);

}

int ft_printf(const char *format, ... )
{
    va_list arg;
    va_start(arg, format);
    t_sc sc;
    int i;

    i = 0;
    sc.len = 0;
    sc.width = 0;

    while(*format)
    {
        if (*format == '%')
            format = ft_search_arg(arg, format + 1, &sc);
        else
            format = ft_read_text(&sc, format);
        if (!format)
        {
            write(1, "(null)", 6);
            va_end(arg);
            return (sc.len);
        }
        va_end(arg);
        return (sc.len);
    }
}

#include <stdio.h>

int main()
{
    int str = 12;
    
    ft_printf("1Hello %d", str);

    return (0);
²}