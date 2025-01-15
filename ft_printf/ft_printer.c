/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:22:48 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/26 10:34:46 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer(char format, va_list args, int *count)
{
	if (ft_is(format) == CHARACTER)
		ft_printf_c(va_arg(args, int), count);
	else if (ft_is(format) == INTEGER)
		ft_printf_i(va_arg(args, int), count);
	else if (ft_is(format) == STRING)
		ft_printf_s((char *)va_arg(args, char *), count);
	else if (ft_is(format) == UNSIGNED_INTEGER)
		ft_printf_u((unsigned int)va_arg(args, unsigned int), count);
	else if (ft_is(format) == POINTER_ADDR)
		ft_printf_p((void *)va_arg(args, void *), count);
	else if (ft_is(format) == HEXA_UP)
		ft_printf_xup((unsigned int)va_arg(args, unsigned int), count);
	else if (ft_is(format) == HEXA_LOW)
		ft_printf_x((unsigned int)va_arg(args, unsigned int), count);
	else if (ft_is(format) == PERCENT)
		ft_printf_per(count);
}
