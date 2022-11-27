/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:06:48 by evscheid          #+#    #+#             */
/*   Updated: 2022/11/28 00:09:03 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(long long int nbr, char *base)
{
	// int			len_base;
	// long long	tab_nub[120];
	// int			i;
	// size_t		len;
	// long long	nbr;

	// nbr = (long long) nb;
	// i = 0;
	// len = 0;
	// len_base = ft_strlen(base);
	// if (nbr == 0 || nbr < -9223372036854775807)
	// 	return (len += ft_putchar_fd('0', 1));
	// if (nbr < 0)
	// {
	// 	nbr = -nbr;
	// 	len += ft_putchar_fd('-', 1);
	// }
	// while (nbr > 0)
	// {
	// 	tab_nub[i++] = nbr % len_base;
	// 	nbr = nbr / len_base;
	// }
	// while (--i >= 0)
	// 	len += ft_putchar_fd(base[tab_nub[i]], 1);
	// return (len);
	long long	n;
	int					len;

	n = nbr;
	len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / len)
		ft_putnbr_base(n / len, base);
	ft_putchar(base[n % len]);
	return 1;
}

int	ft_int_len(long long int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	handleint(long long int n, char *base)
{
	ft_putnbr_base(n, base);
	return (ft_int_len(n));
}

// int main()
// {
// 	int	nbr = -2147483647;
// 	char base[] = "0123456789";

// 	ft_putnbr_base(nbr, base);
// }
