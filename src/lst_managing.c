/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:50:34 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 16:14:25 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*lst_new(void)
{
	t_chain	*new;

	new = malloc(sizeof(t_chain));
	if (!new)
		error();
	new->length = 0;
	new->tail = NULL;
	new->head = NULL;
	return (new);
}

t_chain	*add_node_tail(t_chain *list, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new || !list)
		error();
	new->next = NULL;
	new->data = data;
	if (list->tail != NULL)
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	else
	{
		list->tail = new;
		list->head = new;
		new->prev = NULL;
	}
	list->length++;
	return (list);
}

t_chain	*parsing(t_chain *pile_a, int ac, char **av)
{
	int		i[2];
	int		k;
	char	buff[11];

	i[0] = 1;
	memset(buff, 0, 11);
	k = 0;
	while (av[i[0]])
	{
		i[1] = 0;
		while (av[i[0]][i[1]])
		{
			if (ft_isdigit(av[i[0]][i[1]]) || av[i[0]][i[1]] == '-')
				buff[k++] = av[i[0]][i[1]];
			else if (buff[0])
				k = set_buff(buff, pile_a);
			i[1]++;
		}
		k = set_buff(buff, pile_a);
		i[0]++;
	}
	return (pile_a);
}
