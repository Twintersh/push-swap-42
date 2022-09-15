/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:17:53 by twinters          #+#    #+#             */
/*   Updated: 2022/09/12 20:31:17 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
				error("Error\n", lst);
			tmp = tmp->next;
		}
		checked = checked->next;
	}
}

void	buff_free_error(char **buff, t_chain *lst)
{
	int	i;

	i = 0;
	while (buff[i])
		free(buff[i++]);
	free(buff);
	error("Error\n", lst);
}

void	error(char *c, t_chain *lst)
{
	write(2, c, ft_strlen(c));
	if (lst)
		lst_free(&lst);
	exit(EXIT_FAILURE);
}
