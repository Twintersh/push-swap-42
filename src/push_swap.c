/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/01 12:14:54 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_chain	*pile_a;
	t_node	*current;

	check_error1(argc, argv);
	pile_a = lst_new();
	pile_a = parsing(pile_a, argv);
	check_double(pile_a);
	current = pile_a->head;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	lst_free(&pile_a);
	return (0);
}

void	check_double(t_chain *lst)
{
	t_node	*checked;
	t_node	*tmp;
	int		count;

	checked = lst->head;
	while (checked)
	{
		count = 0;
		tmp = lst->head;
		while (tmp)
		{
			if (checked->data == tmp->data)
				count++;
			if (count > 1)
				error();
			tmp = tmp->next;
		}
		checked = checked->next;
	}
}
