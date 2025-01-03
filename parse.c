/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:39:12 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/03 15:23:59 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include "libft.h"

t_list	*create_list(void)
{
	int		fd;
	char	*str;
	int		i;
	t_list	*lst;

	fd = open("list.txt", O_RDONLY);
	i = 0;
	lst = NULL;
	str = get_next_line(fd);
	
	while (str[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(&str[i])));
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	close(fd);
	free(str);
	return (lst);
}
