/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:46:04 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 16:18:53 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbrhexlow_fd(unsigned int nb, int *count)
{
	if (nb > 15)
	{
		ft_putnbrhexlow_fd((nb / 16), count);
	}
	ft_putchar_count("0123456789abcdef"[nb % 16], count);
}

void	ft_printf_x(unsigned int arg, int *count)
{
	ft_putnbrhexlow_fd(arg, count);
}
