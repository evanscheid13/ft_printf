/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:04:47 by evscheid          #+#    #+#             */
/*   Updated: 2022/11/28 22:30:18 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexx(unsigned int n, char c)
{
	char	*m;
	char	*t;
	char	*s;

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
		ft_hexx(n / 16, c);
		ft_putchar(s[n % 16]);
	}
	return (ft_intlen(n, 16));
}
