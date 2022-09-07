/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:28 by twinters          #+#    #+#             */
/*   Updated: 2022/09/06 19:13:51 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*swap(char c, t_chain *pile)
{
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	if (!pile->head->next || !pile->head)
		return (pile);
	ft_swap(&pile->head->data, &pile->head->next->data);
	return (pile);
}

t_chain	*push(char c, t_chain *src, t_chain *dst)
{
	t_node	*tmp;
	
	if (src->head == NULL)
		return (dst);
	dst = add_node_head(dst, src->head->data);
	if (src->length == 1)
	{
		free(src->head);
		src->head = NULL;
		src->head = NULL;
	}
	else
	{
		tmp = src->head;
		src->head = src->head->next;
		src->head->prev = NULL;
		free(tmp);
		src->length--;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	return (dst);
}

t_chain	*rotate(char c, t_chain *pile)
{
	t_node	*tmp;

	if (pile->length > 1)
	{
		tmp = pile->head->next;
		pile->head->next = NULL;
		pile->head->prev = pile->tail;
		pile->tail->next = pile->head;
		pile->tail = pile->head;
		pile->head = tmp;
		tmp->prev = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	return (pile);
}

t_chain	*rev_rotate(char c, t_chain *pile)
{
	t_node	*tmp;

	if (pile->length <= 1)
		return (pile);
	tmp = pile->tail->prev;
	pile->tail->prev = NULL;
	pile->tail->next = pile->head;
	pile->head->prev = pile->tail;
	pile->head = pile->tail;
	pile->tail = tmp;
	tmp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb", 4);
	return (pile);
}

void	ult_rev_rotate(t_chain *pile1, t_chain *pile2)
{
	pile1 = rev_rotate(' ', pile1);
	pile2 = rev_rotate(' ', pile2);
	write(1, "rrr\n", 4);
}
