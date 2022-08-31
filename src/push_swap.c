/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 16:29:21 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_chain	*pile_a;
	t_node	*current;

	nb_nombres(argc, argv);
	pile_a = lst_new();
	pile_a = parsing(pile_a, argc, argv);
	current = pile_a->head;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	return (0);
}

int	set_buff(char *s, t_chain *pile_a)
{
	add_node_tail(pile_a, ft_atoi(s));
	memset(s, 0, 11);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	num[2];
	int			minus;

	i = 0;
	num[0] = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num[1] = num[0] * 10 + (str[i] - 48);
		if (num[1] < num[0])
			error();
		num[0] = num[1];
		i++;
	}
	num[0] *= minus;
	if (num[0] < INT_MIN || num[0] > INT_MAX)
		error();
	return (num[0]);
}

int	nb_nombres(int ac, char **av)
{
	int	i[2];
	int	k;

	k = 0;
	i[0] = 1;
	while (i[0] < ac)
	{
		i[1] = 0;
		if (!av[i[0]][i[1]])
			error();
		while (av[i[0]][i[1]])
		{
			if (ft_isdigit(av[i[0]][i[1]]) && (i[1] == 0 ||
				av[i[0]][i[1] - 1] == ' ' || av[i[0]][i[1] - 1] == '-'))
				k++;
			else if (!ft_isdigit(av[i[0]][i[1]]) && av[i[0]][i[1]] != ' ')
				error();
			i[1]++;
		}
		i[0]++;
	}
	if (!k)
		error();
	return (k);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
