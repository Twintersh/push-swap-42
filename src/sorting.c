/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:48:40 by twinters          #+#    #+#             */
/*   Updated: 2022/09/02 11:20:36 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*wallah_ca_trie(t_chain *pile_a)
{
	t_chain	*pile_b;
	int		min;

	pile_b = lst_new();
	min = INT_MAX;
	while(pile_a)
	{
		if (pile_a->head->data < min)
			min = pile_a->head->data;
		rotate('a', pile_a);
		if (min == pile_a->head->data && pile_a->head->data != INT_MAX)
		{
			push('b', pile_a, pile_b);
			min = INT_MAX;
		}
	}
	print_lst(pile_b);
	return (pile_b);
}