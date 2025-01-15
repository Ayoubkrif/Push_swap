/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:48:51 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 08:45:37 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_error(void)
{
	ft_putstr_fd("Error !\n", 1);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (ft_is(format[i]) == PERCENT)
		{
			i++;
			if (ft_is(format[i]) == NONE)
				return (ft_put_error());
			ft_printer(format[i], args, &count);
		}
		else
			ft_putchar_count(format[i], &count);
		i++;
	}
	return (count);
}
