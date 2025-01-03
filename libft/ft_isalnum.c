/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:15:05 by ayoub             #+#    #+#             */
/*   Updated: 2024/11/13 07:49:04 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a')
		|| (c <= 'Z' && c >= 'A'))
		return (1);
	return (0);
}
