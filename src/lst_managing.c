/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:50:34 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 12:25:07 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*lst_new(void)
{
	t_chain	*new;

	new = malloc(sizeof(t_chain));
	if (!new)
		exit(EXIT_FAILURE);
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

t_chain	*add_node_tail(t_chain *list, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->next = NULL;
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
