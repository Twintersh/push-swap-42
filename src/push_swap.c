/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:03 by twinters          #+#    #+#             */
/*   Updated: 2022/08/20 19:47:50 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int	*pile_a;
	int	i;

	pile_a = malloc(sizeof(int) * argc);
	while (argv[i + 1])
	{
		pile_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (argv[i + 1])
		ft_printf("%d\n", pile_a[i++]);
}

int	ft_atoi(const char *str)
{
	int	i;
	long int	num[2];
	int	minus;

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
	if (ft_isalnum(str[i]) || (minus == 1 && num[0] > INT_MAX) 
		|| (minus == -1 && num[0] >= INT_MAX))
		error();
	return (num[0] * minus);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
