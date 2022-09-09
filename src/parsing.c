/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:40:08 by twinters          #+#    #+#             */
/*   Updated: 2022/09/09 12:57:47 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*parsing(t_piles *pile, char **av)
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
				add_node_tail(pile->a, ft_atoi(buff[j], pile), -1);
			j++;
		}
		j = 0;
		while (buff[j])
			free(buff[j++]);
		free(buff);
		i++;
	}
	check_double(pile->a);
	return (pile->a);
}

int	ft_atoi(const char *str, t_piles *pile)
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
			error("Error\n", NULL);
		num[0] = num[1];
		i++;
	}
	num[0] *= minus;
	if (num[0] < INT_MIN || num[0] > INT_MAX)
		error("Error\n", NULL);
	return (num[0]);
}

void	check_error1(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		error("Error\n", NULL);
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			error("Error\n", NULL);
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!ft_isdigit(av[i][j + 1]) || ft_isdigit(av[i][j - 1]))
					error("Error\n", NULL);
			}
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
				error("Error\n", NULL);
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
			j++;
		}
		if (!k)
			error("Error\n", NULL);
		i++;
	}
}

void	error(char *c, t_chain **lst)
{
	write(2, c, ft_strlen(c));
	if (lst && *lst)
		lst_free(lst);
	exit(EXIT_FAILURE);
}
