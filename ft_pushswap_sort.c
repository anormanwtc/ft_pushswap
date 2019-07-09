/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:20:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 14:34:37 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static t_stk	*st_stackdup(t_stk *stack)
{
	t_stk	*curs;
	t_stk	*new;
	
	if (!stack)
		return (NULL);
	curs = stack->next;
	new = NULL;
	while (curs != stack)
	{
		new = ft_stackadd(new, curs->prev->val);
		curs = curs->next;
	}
	new = ft_stackadd(new, curs->prev->val);
	return (new);
}

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

t_list			*ft_recursort(t_stk *stack)
{
	t_list	*commands;
	t_stk	*curser;
	static int goal;

	if (!goal)
		goal = st_basicsort(st_stackdup(stack));
	curser = stack->next;
	commands = NULL;
	return (commands);
}
