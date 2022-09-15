/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:04:43 by twinters          #+#    #+#             */
/*   Updated: 2022/09/13 15:58:49 by twinters         ###   ########.fr       */
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

	set_index(pile_a);
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

void	sort3(t_chain *lst)
{
	t_node	*tmp;

	set_index(lst);
	tmp = lst->head;
	if (check_sorted(lst))
		return ;
	while (tmp->next)
	{
		if (tmp->index == 2 && tmp->next->index == 0)
		{
			if (tmp == lst->head)
				rotate("ra\n", lst);
			else
				rev_rotate("rra\n", lst);
			return ;
		}
		tmp = tmp->next;
	}
	swap("sa\n", lst);
	sort3(lst);
}

void	sort50(t_chain *pile_a, t_chain *pile_b)
{
	size_t	index_lower;

	while (pile_a->length > 3)
	{
		index_lower = get_lower_index(pile_a);
		if (index_lower > pile_a->length / 2)
			while (get_lower_index(pile_a) != 0)
				rev_rotate("rra\n", pile_a);
		else
			while (get_lower_index(pile_a) != 0)
				rotate("ra\n", pile_a);
		push("pb\n", pile_a, pile_b);
	}
	sort3(pile_a);
	while (pile_b->head)
		push("pa\n", pile_b, pile_a);
}
