/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/01 21:45:43 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main()
{
	t_chain *pile_a = lst_new();
	t_chain *pile_b = lst_new();
	t_node *cur_a;
	t_node *cur_b;

	for (int i = 0; i < 10 ; i++)
	{
		add_node_tail(pile_a, i);
		add_node_tail(pile_b, i + 42);
	}
	/*--------------------------------*/
	push('a', pile_b, pile_a);
	push('a', pile_b, pile_a);
	/*--------------------------------*/
	cur_a = pile_a->head;
	cur_b = pile_b->head;
	while (cur_a || cur_b)
	{
		if (cur_a)
		{
			printf("a%d ", cur_a->data);
			cur_a = cur_a->next;
		}
		if (cur_b)
		{
			printf("b%d", cur_b->data);
			cur_b = cur_b->next;
		}
		printf("\n");
	}
}

// int	main(int argc, char **argv)
// {
// 	t_chain	*pile_a;
// 	t_node	*current_a;

// 	check_error1(argc, argv);
// 	pile_a = lst_new();
// 	pile_a = parsing(pile_a, argv);
// 	current_a = pile_a->head;
// 	while (current_a)
// 	{
// 		ft_printf("%d\n", current_a->data);
// 		current_a = current_a->next;
// 	}
// 	lst_free(&pile_a);
// 	return (0);
// }

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
		add_node_tail(pile_a, ft_atoi(s));
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
