/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:41:20 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 15:50:59 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*st_shortstk_sort(t_stk **stack)
{
	int		max;
	t_list *commands;

	commands = NULL;
	if (len < 2)
		return (ft_lstnew("", 1));
	if ((*stack)->len == 2)
		if ((*stack)->start[0] > (*stack)->start[1])
			return (ft_lstnew("sa", 3));
	if ((*stack)->len == 3)
	{
		max = ft_stackmax(*stack);
		if (max == 0)
			commands = ft_lstnew("ra", 3);
		else if (max == 1)
			commands = ft_lstnew("rra", 4);
		if ((*stack)->start[0] > (*stack)->start[1])
			ft_lstadd(&commands, ft_lstnew("sa", 3));
	}
	return (commands);
}

t_list			*ft_stksort(t_stk **stack)
{
	if (ft_stackcheck(stack))
		return (ft_lstnew("", 1));
	if (stack[0]->len < 3)
		return (st_shortstk_sort(stack));
	return (ft_bigstk_sort(stack));
}



