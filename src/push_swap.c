/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 19:40:27 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_chain	*pile_a;
	t_node	*current;

	check_error1(argc, argv);
	pile_a = lst_new();
	pile_a = parsing(pile_a, argc, argv);
	current = pile_a->head;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	lst_free(&pile_a);
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

void	check_error1(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		error();
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			error();
		while (av[i][j])
		{
			if (av[i][j] == '-')
			{
				if (!ft_isdigit(av[i][j + 1]) || ft_isdigit(av[i][j - 1]))
					error();
			}
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
				error();
			j++;
		}
		i++;
	}
	check_error2(ac, av);
}

void	check_error2(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				k++;
			if (av[i][j] == ' ')
				k = 0;
			j++;
		}
		if (!k)
			error();
		i++;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
