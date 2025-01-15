/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:02:30 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/15 10:07:45 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isisspace(int c)
{
	return ((c <= 13 && c >= 9) || c == ' ');
}

long	ft_atol(const char *nptr)
{
	long	r;
	int		s;
	int		i;

	i = 0;
	s = 1;
	r = 0;
	while (ft_isisspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	return (s * r);
}
