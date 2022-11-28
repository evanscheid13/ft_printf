/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:29:43 by evscheid          #+#    #+#             */
/*   Updated: 2022/11/28 22:39:18 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"
# include <stdio.h>

int		ft_hexa(unsigned long long int n, char *s);
int		print_pointer(unsigned long long int n, char *base);
int		ft_intlen(unsigned int n, int base);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_putstr(char *str);
void	ft_unsign(unsigned int n);
size_t	ft_putnbr_base(long long int nb, char *base);
int		handleint(long long int n, char *base);
int		ft_strlen(char *s);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
int		ft_hexx(unsigned int n, char c);
#endif