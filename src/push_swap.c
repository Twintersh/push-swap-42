/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/08/21 08:01:19 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	// int		*pile_a;
	// char	**buff_arg;
	// int		i;
	int nombre = nb_nombres(argc, argv);
	printf("%d\n", nombre);
	return (0);
}

int	nb_nombres(int ac, char **av)
{
	int	i;
	int	j;
	int	nb_nb;

	nb_nb = 0;
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j] && (j == 0 || av[i][j - 1] == ' ')))
				{nb_nb++;printf("%d %d %d\n", i, j, nb_nb);}
			j++;
		}
		i++;
	}
	return (nb_nb);
}

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	long int	num[2];
// 	int	minus;

// 	i = 0;
// 	num[0] = 0;
// 	minus = 1;
// 	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
// 		|| str[i] == '\f' || str[i] == '\r')
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 		if (str[i++] == '-')
// 			minus *= -1;
// 	while (str[i] >= 48 && str[i] <= 57)
// 	{
// 		num[1] = num[0] * 10 + (str[i] - 48);
// 		if (num[1] < num[0])
// 			error();
// 		num[0] = num[1];
// 		i++;
// 	}
// 	if (ft_isalnum(str[i]) || (minus == 1 && num[0] > INT_MAX) 
// 		|| (minus == -1 && num[0] >= INT_MAX))
// 		error();
// 	return (num[0] * minus);
// }

// void	error(void)
// {
// 	write(2, "Error\n", 6);
// 	exit(EXIT_FAILURE);
// }
