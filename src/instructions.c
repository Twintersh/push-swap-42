/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:28 by twinters          #+#    #+#             */
/*   Updated: 2022/09/02 15:36:40 by twinters         ###   ########.fr       */
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
		pile->tail->next = pile->head;
		pile->tail = pile->head;
		pile->head = tmp;
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

	if (pile->length > 1)
	{
		pile->tail->next = pile->head;
		pile->head = pile->tail;
		pile->tail = tmp;
		tmp->next = NULL;
	}
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
