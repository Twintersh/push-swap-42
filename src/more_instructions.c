/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:32:31 by twinters          #+#    #+#             */
/*   Updated: 2022/09/12 20:34:13 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ult_rotate(t_chain *pile1, t_chain *pile2)
{
	pile1 = rotate(" ", pile1);
	pile2 = rotate(" ", pile2);
	write(1, "rr\n", 3);
}

void	ult_swap(t_chain *pile1, t_chain *pile2)
{
	pile1 = swap(" ", pile1);
	pile2 = swap(" ", pile2);
	write(1, "ss\n", 3);
}
