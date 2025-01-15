/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:37:23 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 14:33:22 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbrhexup_fd(unsigned int nb, int *count)
{
	if (nb > 15)
	{
		ft_putnbrhexup_fd((nb / 16), count);
	}
	ft_putchar_count("0123456789ABCDEF"[nb % 16], count);
}

void	ft_printf_xup(unsigned int arg, int *count)
{
	ft_putnbrhexup_fd(arg, count);
}
