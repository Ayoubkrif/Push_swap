/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:07:13 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 14:47:17 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putun_fd(unsigned int nb, int *count)
{
	if (nb > 9)
	{
		ft_putun_fd((nb / 10), count);
	}
	ft_putchar_count("0123456789"[nb % 10], count);
}

void	ft_printf_u(unsigned int arg, int *count)
{
	ft_putun_fd(arg, count);
}
