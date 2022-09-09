/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:50:34 by twinters          #+#    #+#             */
/*   Updated: 2022/09/09 09:50:50 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*lst_new(void)
{
	t_chain	*new;

	new = malloc(sizeof(t_chain));
	if (!new)
		error("Error\n", NULL);
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

t_chain	*add_node_tail(t_chain *list, int data, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new || !list)
		error("Error\n", &list);
	new->next = NULL;
	new->index = index;
	new->data = data;
	if (list->tail != NULL)
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	else
	{
		list->tail = new;
		list->head = new;
		new->prev = NULL;
	}
	list->length++;
	return (list);
}

t_chain	*add_node_head(t_chain *list, int data, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new || !list)
		error("Error\n", &list);
	new->prev = NULL;
	new->data = data;
	new->index = index;
	if (list->head != NULL)
	{
		list->head->prev = new;
		new->next = list->head;
		list->head = new;
	}
	else
	{
		list->tail = new;
		list->head = new;
		new->next = NULL;
	}
	list->length++;
	return (list);
}

void	lst_free(t_chain **lst)
{
	t_node	*tmp;
	t_node	*del;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->head;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(*lst);
	*lst = NULL;
}
