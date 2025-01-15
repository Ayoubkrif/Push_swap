/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:36:53 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 09:20:35 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddress_fd(unsigned long long nb, int *count)
{
	if (nb > 15)
	{
		ft_putaddress_fd((nb / 16), count);
	}
	ft_putchar_count("0123456789abcdef"[nb % 16], count);
}

void	ft_printf_p(void *arg, int *count)
{
	unsigned long long	arg_casted;

	arg_casted = (unsigned long long)arg;
	if (arg != 0)
	{
		ft_putchar_count('0', count);
		ft_putchar_count('x', count);
		ft_putaddress_fd(arg_casted, count);
	}
	else
		ft_printf_s("(nil)", count);
}
