/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_sortcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/17 12:18:15 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackcheck(t_stk **stack)
{
	int		*curs;
	int		len;

	if (stack[1]->len)
		return (0);
	if (!(stack[0]->len))
		return (1);
	curs = stack[0]->start;
	len = stack[0]->len;
	while (len--)
	{
		if (curs[0] > curs[1])
			return (0);
		curs++;
	}
	return (1);
}

long		ft_basicsort_goal(int len)
{
	long res;

	len--;
	res = 2 * (long)len;
	while (len)
	{
		res += ((long)len / 2);
		len--;
	}
	return (res);
}
