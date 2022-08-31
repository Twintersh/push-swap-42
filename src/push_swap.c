/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 13:57:34 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		nb;
	t_chain	*pile_a;
	t_node	*current;

	nb = nb_nombres(argc, argv);
	pile_a = lst_new();
	ft_printf("%d\n", nb);
	pile_a = parsing(pile_a, argc, argv);
	current = pile_a->head;
	while(current->next)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	return (0);
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
			{
				buff[k++] = av[i[0]][i[1]];
			}
			else if (buff[0])
			{
				add_node_tail(pile_a, ft_atoi(buff));
				memset(buff, 0, 11);
				k = 0;
			}
			i[1]++;
		}
		k = 0;
		memset(buff, 0, 11);
		add_node_tail(pile_a, ft_atoi(buff));
		i[0]++;
	}
	return (pile_a);
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
	if (ft_isdigit(str[i]) || (minus == 1 && num[0] > INT_MAX)
		|| (minus == -1 && num[0] >= INT_MAX))
		error();
	return (num[0] * minus);
}

int	nb_nombres(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			error();
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) && (j == 0 ||
				av[i][j - 1] == ' ' || av[i][j - 1] == '-'))
				k++;
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
				error();
			j++;
		}
		i++;
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
