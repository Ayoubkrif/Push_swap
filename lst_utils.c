/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:27 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/09 16:12:49 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (!node)
		return ;
	if (!(*lst))
	{
		node->next = NULL;
		*lst = node;
		node->prev = NULL;
		return ;
	}
	(*lst)->prev = node;
	node->next = *lst;
	*lst = node;
	node->prev = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = node;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->next = NULL;
	node->prev = current;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (lst);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

int	ft_lstsize(t_list *lst)
{
	int	r;

	r = 0;
	while (lst)
	{
		lst = lst->next;
		r++;
	}
	return (r);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->nbr = nb;
	newlst->index = 0;
	newlst->next = NULL;
	newlst->prev = NULL;
	return (newlst);
}
