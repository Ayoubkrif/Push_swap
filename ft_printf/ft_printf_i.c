/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:03:46 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 16:12:14 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_count(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_printf_s("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_count('-', count);
	}
	if (nb > 9)
	{
		ft_putnbr_count((nb / 10), count);
	}
	ft_putchar_count("0123456789"[nb % 10], count);
}

void	ft_printf_i(int arg, int *count)
{
	ft_putnbr_count(arg, count);
}
