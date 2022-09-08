/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:21:28 by twinters          #+#    #+#             */
/*   Updated: 2022/09/08 19:04:38 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*swap(char *c, t_chain *pile)
{
	write(1, c, ft_strlen(c));
	if (!pile->head->next || !pile->head)
		return (pile);
	ft_swap(&pile->head->data, &pile->head->next->data);
	return (pile);
}

t_chain	*push(char *c, t_chain *src, t_chain *dst)
{
	t_node	*tmp;

	write(1, c, ft_strlen(c));
	if (src->head == NULL)
		return (dst);
	dst = add_node_head(dst, src->head->data, src->head->index);
	if (src->length == 1)
	{
		free(src->head);
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		tmp = src->head;
		src->head = src->head->next;
		src->head->prev = NULL;
		free(tmp);
	}
	src->length--;
	return (dst);
}

t_chain	*rotate(char *c, t_chain *pile)
{
	t_node	*tmp;

	write(1, c, ft_strlen(c));
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
	return (pile);
}

t_chain	*rev_rotate(char *c, t_chain *pile)
{
	t_node	*tmp;

	write(1, c, ft_strlen(c));
	if (pile->length <= 1)
		return (pile);
	tmp = pile->tail->prev;
	pile->tail->prev = NULL;
	pile->tail->next = pile->head;
	pile->head->prev = pile->tail;
	pile->head = pile->tail;
	pile->tail = tmp;
	tmp->next = NULL;
	return (pile);
}

void	ult_rev_rotate(t_chain *pile1, t_chain *pile2)
{
	pile1 = rev_rotate(" ", pile1);
	pile2 = rev_rotate(" ", pile2);
	write(1, "rrr\n", 4);
}
