/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:41:30 by twinters          #+#    #+#             */
/*   Updated: 2022/09/13 16:03:13 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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
	struct s_chain	*pile_b;
	size_t			length;
}t_chain;

// main_parsing.c

int			main(int argc, char **argv);
t_chain		*parsing(t_chain *pile_a, char **av);
int			ft_atoi(char **str, t_chain *lst, int j);
t_chain		*choose_sort_alg(t_chain *pile_a);
int			check_sorted(t_chain *pile_a);

// lst_managing.c

t_chain		*lst_new(t_chain *lst);
t_chain		*add_node_tail(t_chain *list, int data, int index);
t_chain		*add_node_head(t_chain *list, int data, int index);
void		lst_free(t_chain **lst);
size_t		get_lower_index(t_chain *pile);

// errors.c

void		check_error1(int ac, char **av);
void		check_error2(int ac, char **av);
void		check_double(t_chain *lst);
void		buff_free_error(char **buff, t_chain *lst);
void		error(char *c, t_chain *lst);

// instructions.c

t_chain		*swap(char *c, t_chain *pile);
t_chain		*push(char *c, t_chain *src, t_chain *dst);
t_chain		*rotate(char *c, t_chain *pile);
t_chain		*rev_rotate(char *c, t_chain *pile);
void		ult_rev_rotate(t_chain *pile1, t_chain *pile2);

// more_instructions.c

void		ult_rotate(t_chain *pile1, t_chain *pile2);
void		ult_swap(t_chain *pile1, t_chain *pile2);

// sorting.c

t_chain		*set_index(t_chain *pile_a);
int			get_bits(int len);
void		radix(t_chain *pile_a, t_chain *pile_b);
void		sort3(t_chain *pile_a);
void		sort50(t_chain *pile_a, t_chain *pile_b);

#endif