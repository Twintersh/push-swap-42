/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:11:15 by twinters          #+#    #+#             */
/*   Updated: 2022/08/29 21:45:17 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib-twinters/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483648

typedef struct s_lst
{
	struct s_lst	*prev;
	int				data;
	struct s_lst	*next;
}t_lst;

void	error(void);
int		nb_nombres(int ac, char **av);

// lst_managing

void	insert_data(t_lst node, int data);

#endif