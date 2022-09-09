/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/09 15:43:36 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_piles	*pile;

	check_error1(argc, argv);
	pile->a = lst_new();
	pile->b = lst_new();
	pile->a = parsing(pile, argv);
	pile->b = set_index(pile->a);
	radix(pile->a, pile->b);
	lst_free(&pilex);
	return (0);
}

void	check_double(t_chain *lst)
{
	t_node	*checked;
	t_node	*tmp;
	int		count;

	if (!lst)
		return ;
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
				error("Error\n", &lst);
			tmp = tmp->next;
		}
		checked = checked->next;
	}
}

void	ult_rotate(t_chain *pile1, t_chain *pile2)
{
	pile1 = rotate(" ", pile1);
	pile2 = rotate(" ", pile2);
	write(1, "rr\n", 3);
}

void	ult_swap(t_chain *pile1, t_chain *pile2)
{
	pile1 = swap(" ", pile1);
	pile2 = swap(" ", pile2);
	write(1, "ss\n", 3);
}
