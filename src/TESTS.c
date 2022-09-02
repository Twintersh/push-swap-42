/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTS.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:41:31 by twinters          #+#    #+#             */
/*   Updated: 2022/09/02 10:46:11 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// AU MOMENT DE LA SUPPRESSION, EFFACER AUSSI DANS LE MAKEFILE !

void	print_lst(t_chain *lst)
{
	t_node *cur;

	cur = lst->head;
	while (cur)
	{
		ft_printf("%d\n", cur->data);
		cur = cur->next;
	}
}

// int	main(void)
// {
// 	t_chain	*pile_a = lst_new();
// 	t_chain	*pile_b = lst_new();
// 	t_node	*cur_a;
// 	t_node	*cur_b;

// 	for (int i = 0; i < 10 ; i++)
// 	{
// 		add_node_tail(pile_a, i);
// 		add_node_tail(pile_b, i + 42);
// 	}
// 	/*--------------------------------*/
// 	push('a', pile_b, pile_a);
// 	push('a', pile_b, pile_a);
// 	/*--------------------------------*/
// 	cur_a = pile_a->head;
// 	cur_b = pile_b->head;
// 	while (cur_a || cur_b)
// 	{
// 		if (cur_a)
// 		{
// 			printf("a%d ", cur_a->data);
// 			cur_a = cur_a->next;
// 		}
// 		if (cur_b)
// 		{
// 			printf("b%d", cur_b->data);
// 			cur_b = cur_b->next;
// 		}
// 		printf("\n");
// 	}
// }