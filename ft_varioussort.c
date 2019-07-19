/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varioussort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:45:51 by anorman           #+#    #+#             */
/*   Updated: 2019/07/19 17:49:21 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_ps_len3(t_stk **stack)
{
	int		max;
	t_list *commands;

	commands = NULL;
	if (ft_stackcheck(stack))
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
