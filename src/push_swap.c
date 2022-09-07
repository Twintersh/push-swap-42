/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/07 20:53:07 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_chain	*pile_a;
	t_chain	*pile_b;

	check_error1(argc, argv);
	pile_a = lst_new();
	pile_b = lst_new();
	pile_a = parsing(pile_a, argv);
	pile_a = set_index(pile_a);
	radix(pile_a, pile_b);
	print_lst(pile_a);
	lst_free(&pile_a);
	lst_free(&pile_b);
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

int	set_buff(char *s, t_chain *pile_a)
{
	if (s[0])
		add_node_tail(pile_a, ft_atoi(s), -1);
	ft_memset(s, 0, 11);
	return (0);
}

void	ult_rotate(t_chain *pile1, t_chain *pile2)
{
	pile1 = rotate(' ', pile1);
	pile2 = rotate(' ', pile2);
	write(1, "rr\n", 3);
}

void	ult_swap(t_chain *pile1, t_chain *pile2)
{
	pile1 = swap(' ', pile1);
	pile2 = swap(' ', pile2);
	write(1, "ss\n", 3);
}
