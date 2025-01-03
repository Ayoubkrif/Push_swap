/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:27 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/03 12:08:15 by aykrifa          ###   ########.fr       */
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
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->prev = current;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

void	ft_printlist(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->nbr);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
}

void	ft_printlist_index(t_list *lst)
{
	if (!lst)
		printf("empty!");
	while (lst)
	{
		printf("%d", lst->index);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
}

void	ft_printlist_decile(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->decile);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
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




t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*head;
	int		fcontent;

	fcontent = (lst->nbr);
	head = ft_lstnew(fcontent);
	if (!head)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		fcontent = lst->nbr;
		new = ft_lstnew(fcontent);
		if (new == NULL)
		{
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

void	sort_list(t_list *head)
{
	t_list	*i;
	t_list	*j;
	int		temp;

	if (head == NULL)
		return ;
	i = head;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->nbr > j->nbr)
			{
				temp = i->nbr;
				i->nbr = j->nbr;
				j->nbr = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
