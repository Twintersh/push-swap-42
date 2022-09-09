/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTS.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:46:55 by twinters          #+#    #+#             */
/*   Updated: 2022/09/08 17:56:05 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DONT FORGET TO DELETE THAT FILE FROM THE MAKEFILE BEFORE PUSHING THE REPO

#include "../push_swap.h"

// int main()
// {
// 	t_chain *pile_a = lst_new();
// 	t_chain *pile_b = lst_new();
// 	t_node *cur_a;
// 	t_node *cur_b;

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

// void	print_lst(t_chain *lst)
// {
// 	t_node	*cur;

// 	cur = lst->head;
// 	while (cur)
// 	{
// 		ft_printf("%d\n", cur->data);
// 		cur = cur->next;
// 	}
// }

// void	wallah_ca_trie(t_chain *pile_a, t_chain *pile_b)
// {
// 	int	min;

// 	min = INT_MAX;
// 	while (pile_a->head != NULL)
// 	{
// 		if (pile_a->head->data < min)
// 			min = pile_a->head->data;
// 		else if (min == pile_a->head->data)
// 		{
// 			push("pb\n", pile_a, pile_b);
// 			min = INT_MAX;
// 		}
// 		rotate("ra\n", pile_a);
// 	}
// 	while (pile_b->head != NULL)
// 		push("pa\n", pile_b, pile_a);
// }