/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/13 15:58:59 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_chain	*pile_a;
	t_chain	*pile_b;

	check_error1(argc, argv);
	pile_b = lst_new(NULL);
	pile_a = lst_new(pile_b);
	pile_a = parsing(pile_a, argv);
	choose_sort_alg(pile_a);
	lst_free(&pile_a);
	return (0);
}

t_chain	*parsing(t_chain *pile_a, char **av)
{
	int		i;
	int		j;
	char	**buff;

	i = 1;
	buff = NULL;
	while (av[i])
	{
		j = 0;
		if (av[i][0])
			buff = ft_split(av[i], ' ');
		while (buff[j])
		{
			if (buff[j][0])
				add_node_tail(pile_a, ft_atoi(buff, pile_a, j), -1);
			j++;
		}
		j = 0;
		while (buff[j])
			free(buff[j++]);
		free(buff);
		i++;
	}
	check_double(pile_a);
	return (pile_a);
}

int	ft_atoi(char **str, t_chain *lst, int j)
{
	int			i;
	long int	num[2];
	int			minus;

	i = 0;
	num[0] = 0;
	minus = 1;
	while (str[j][i] == ' ' || str[j][i] == '\n' || str[j][i] == '\t'
		|| str[j][i] == '\v' || str[j][i] == '\f' || str[j][i] == '\r')
		i++;
	if (str[j][i] == '+' || str[j][i] == '-')
		if (str[j][i++] == '-')
			minus *= -1;
	while (str[j][i] >= 48 && str[j][i] <= 57)
	{
		num[1] = num[0] * 10 + (str[j][i] - 48);
		if (num[1] < num[0])
			buff_free_error(str, lst);
		num[0] = num[1];
		i++;
	}
	num[0] *= minus;
	if (num[0] < INT_MIN || num[0] > INT_MAX)
		buff_free_error(str, lst);
	return (num[0]);
}

t_chain	*choose_sort_alg(t_chain *pile_a)
{
	if (check_sorted(pile_a))
		return (pile_a);
	if (pile_a->length == 2)
		swap("sa\n", pile_a);
	else if (pile_a->length == 3)
		sort3(pile_a);
	else if (pile_a->length <= 50)
		sort50(pile_a, pile_a->pile_b);
	else
		radix(pile_a, pile_a->pile_b);
	return (pile_a);
}

int	check_sorted(t_chain *pile_a)
{
	t_node	*tmp;

	tmp = pile_a->head;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
