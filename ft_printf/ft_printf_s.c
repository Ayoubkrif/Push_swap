/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:46:01 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/19 14:34:00 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(char *arg, int *count)
{
	int	i;

	i = 0;
	if (!arg)
	{
		ft_printf_s("(null)", count);
		return ;
	}
	while (arg[i])
		ft_putchar_count(arg[i++], count);
}
