/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:41:30 by twinters          #+#    #+#             */
/*   Updated: 2022/08/31 18:52:48 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib-twinters/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	struct s_node	*next;
	int				data;
	struct s_node	*prev;
}t_node;

typedef struct s_chain
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			length;
}t_chain;

// push_swap.c

void	error(void);
void	check_error1(int ac, char **av);
void	check_error2(int ac, char **av);
int		set_buff(char *s, t_chain *pile_a);

// lst_managing

t_chain	*parsing(t_chain *pile_a, int ac, char **av);
t_chain	*lst_new(void);
t_chain	*add_node_tail(t_chain *list, int data);

#endif