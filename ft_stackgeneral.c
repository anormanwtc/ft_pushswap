/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackgeneral.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/13 12:09:27 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftpushswap.h"

int		ft_stackcheck(t_stk **stack)
{
	t_stk	*curs;

	if (stack[1])
		return (0);
	if (!stack[0])
		return (1);
	curs = (stack[0])->next;
	while (curs != stack[0])
	{
		if (curs->val < curs->prev->val)
			return (0);
		curs = curs->next;
	}
	return (1);
}

t_stk	*ft_stackdup(t_stk *stack)
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

int		ft_basicsort_goal(int len)
{
	int res;

	res = 2 * len;
	while (len)
	{
		res += (len / 2);
		len--;
	}
	return (res);
}

int		ft_stacklen(t_stk *start)
{
	t_stk	*curs;
	int		res;

	if (!start)
		return (0);
	res = 1;
	curs = start->next;
	while (curs != start)
	{
		res++;
		curs = curs->next;
	}
	return (res);
}
