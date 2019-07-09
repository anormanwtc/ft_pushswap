/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:20:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 16:04:31 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static int		st_basicsort(t_stk *stack)
{
	t_stk	*a_b[2];
	int		res;

	if (!stack)
		return (0);
	a_b[0] = stack;
	a_b[1] = NULL;
	res = 0;
	while (!ft_stackcheck(a_b))
	{
		if (a_b[0]->val > a_b[0]->next->val && ++res)
			ft_stkswap('a', a_b);
		ft_stkrotate('A', a_b);
	}
	ft_stackprint(a_b[0]);
	ft_stackdel(stack);
	return (res);
}

t_list			*ft_recurswap(t_stk **stack, int steps)
{
		ft_stkswap('a', stack);
		if ((commands = ft_recursort(stack, steps + 1)))
			return (ft_lstadd(commands, ft_lstnew("sa", 3)));
		ft_stkswap('a', stack);
		ft_stkswap('b', stack);
		if ((commands = ft_recursort(stack, steps + 1)))
			return (ft_lstadd(commands, ft_lstnew("sa", 3)));
		ft_stkswap('b', stack);
}


t_list			*ft_recursort(t_stk **stack, int steps)
{
	t_list		*commands;
	static int	goal;

	if (!goal)
		goal = st_basicsort(st_stackdup(stack));
	commands = NULL;
	while (steps < goal && !ft_stackcheck(stack))
	{

	}
	return (commands);
}
