/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:28:52 by twinters          #+#    #+#             */
/*   Updated: 2022/08/29 21:45:18 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int main()
// {
// 	t_lst *test;
// 	t_lst *test2;

// 	test->data = 1;
// 	test2->data = 2;
// 	test->next = test2;
// 	test2->prev = test;

// 	printf("%d %d", test->data, test->next->data);
// }

void	insert_data(t_lst *node, int data)
{
	if (node == NULL)
			exit(EXIT_FAILURE);
	t_lst new_node;
	new_node->next = node->next;
	node->next = new_node;
	new_node->prev = node;
	new_node->data = data;
}