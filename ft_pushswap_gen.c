/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 15:55:10 by anorman          ###   ########.fr       */
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
