/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:04:43 by twinters          #+#    #+#             */
/*   Updated: 2022/09/08 18:06:35 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*set_index(t_chain *pile_a)
{
	size_t	i;
	t_node	*min;
	t_node	*tmp;

	i = 0;
	tmp = pile_a->head;
	while (i < pile_a->length)
	{
		min = pile_a->head;
		tmp = pile_a->head;
		while (tmp)
		{
			if (min->index != -1 && tmp->index == -1)
				min = tmp;
			if (min->data > tmp->data && tmp->index == -1)
				min = tmp;
			tmp = tmp->next;
		}
		min->index = i;
		i++;
	}
	return (pile_a);
}

int	get_bits(int len)
{
	int	nb_bits;

	nb_bits = 0;
	while (len >> nb_bits)
		nb_bits++;
	return (nb_bits);
}

void	radix(t_chain *pile_a, t_chain *pile_b)
{
	int	len;
	int	i;
	int	j;
	int	max_bit;

	len = pile_a->length;
	max_bit = get_bits(len - 1);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < len)
		{
			if ((pile_a->head->index >> i) & 1)
				rotate("ra\n", pile_a);
			else
				push("pb\n", pile_a, pile_b);
			j++;
		}
		i++;
		while (pile_b->head)
			push("pa\n", pile_b, pile_a);
	}
}
