/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:41:20 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 17:52:36 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		st_shortstk_sort(t_stk **stack)
{
	int		max;
	t_list *commands;

	commands = NULL;
	if ((*stack)->len == 2)
		if ((*stack)->start[0] > (*stack)->start[1])
			write(1, "sa\n", 3);
	if ((*stack)->len == 3)
	{
		max = ft_stackmax(*stack);
		if (max == 0)
			write(1, "ra\n", 3);
		else if (max == 1)
			write(1, "rra\n", 4);
		if ((*stack)->start[0] > (*stack)->start[1])
			write(1, "sa\n", 3);
	}
}

void			ft_stksort(t_stk **stack)
{
	if (ft_stackcheck(stack))
		return ;
	if (stack[0]->len < 3)
		st_shortstk_sort(stack);
	else
		ft_bigsort(stack);
}
