/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:28:44 by marvin            #+#    #+#             */
/*   Updated: 2022/11/25 20:28:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_printf.h"

void	ft_unsign(unsigned int n, int *t);
int		ft_hexa(unsigned int n, char c);
void	ft_putnbr(int n);
int		ft_putstr(char *s);
void	ft_putchar(char c);
#endif