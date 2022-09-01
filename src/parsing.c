/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:40:08 by twinters          #+#    #+#             */
/*   Updated: 2022/09/01 12:05:47 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chain	*parsing(t_chain *pile_a, char **av)
{
	int		i;
	int		j;
	int		k;
	char	buff[11];

	i = 1;
	ft_memset(buff, 0, 11);
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || av[i][j] == '-')
				buff[k++] = av[i][j];
			else if (buff[0])
				k = set_buff(buff, pile_a);
			j++;
		}
		k = set_buff(buff, pile_a);
		i++;
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
