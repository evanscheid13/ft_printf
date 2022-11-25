/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:29:43 by evscheid          #+#    #+#             */
/*   Updated: 2022/11/25 22:35:51 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
# include "ft_printf.h"

int 	ft_hexa(unsigned int n, char c);
int		ft_intlen(unsigned int n, int base);
int 	ft_printf(const char *s, ...);
void    ft_putchar(char c);
void    ft_putnbr(int n);
void    ft_putstr(char *str);
void	ft_unsign(unsigned int n);
#endif