/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:41:30 by twinters          #+#    #+#             */
/*   Updated: 2022/09/09 12:58:39 by twinters         ###   ########.fr       */
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
	int				index;
	struct s_node	*prev;
}t_node;

typedef struct s_chain
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			length;
}t_chain;

typedef struct s_piles
{
	struct s_chain	*a;
	struct s_chain	*b;
}t_piles;

// main.c

int			main(int argc, char **argv);
void		check_double(t_chain *lst);
int			set_buff(char *s, t_chain *pile_a);
void		ult_swap(t_chain *pile1, t_chain *pile2);
void		ult_rotate(t_chain *pile1, t_chain *pile2);

// lst_managing.c

t_chain		*lst_new(void);
t_chain		*add_node_tail(t_chain *list, int data, int index);
t_chain		*add_node_head(t_chain *list, int data, int index);
void		lst_free(t_chain **lst);

// parsing.c

t_chain		*parsing(t_piles *pile, char **av);
int			ft_atoi(const char *str, t_piles*);
void		error(char *c, t_chain **lst);
void		check_error1(int ac, char **av);
void		check_error2(int ac, char **av);

// instructions.c

t_chain		*swap(char *c, t_chain *pile);
t_chain		*push(char *c, t_chain *src, t_chain *dst);
t_chain		*rotate(char *c, t_chain *pile);
t_chain		*rev_rotate(char *c, t_chain *pile);
void		ult_rev_rotate(t_chain *pile1, t_chain *pile2);

// sorting.c

t_chain		*set_index(t_chain *pile_a);
int			get_bits(int len);
void		radix(t_chain *pile_a, t_chain *pile_b);

// TESTS.c

void		print_lst(t_chain *lst);
void		wallah_ca_trie(t_chain *pile_a, t_chain *pile_b);

#endif