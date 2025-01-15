/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:14:49 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 16:15:55 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conversion	ft_is(const char c)
{
	if (c == 'c')
		return (CHARACTER);
	if (c == 'i' || c == 'd')
		return (INTEGER);
	if (c == 's')
		return (STRING);
	if (c == 'u')
		return (UNSIGNED_INTEGER);
	if (c == 'p')
		return (POINTER_ADDR);
	if (c == '%')
		return (PERCENT);
	if (c == 'x')
		return (HEXA_LOW);
	if (c == 'X')
		return (HEXA_UP);
	return (NONE);
}
