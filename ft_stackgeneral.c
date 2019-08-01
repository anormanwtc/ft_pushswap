/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_sortcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/26 18:03:36 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackcheck(t_stk **stack)
{
	int		*curs;
	int		len;

	if (stack[1]->len)
		return (0);
	if ((stack[0]->len) < 2)
		return (1);
	curs = stack[0]->start;
	len = stack[0]->len;
	while (--len)
	{
		if (curs[0] > curs[1])
			return (0);
		curs++;
	}
	return (1);
}

int		ft_no_dups(t_stk *stack)
{
	int i;
	int k;

	i = 0;
	while (i < stack->len)
	{
		k = i + 1;
		while (k < stack->len)
		{
			if (stack->start[i] == stack->start[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int		ft_stackmin(t_stk *stack)
{
	int		ind;
	int		i;
	int		*curs;

	if (!stack)
		return (-1);
	i = 1;
	ind = 0;
	curs = stack->start;
	while (i < stack->len)
	{
		if (curs[ind] > curs[i])
			ind = i;
		i++;
	}
	return (ind);
}

int		ft_stackmax(t_stk *stack)
{
	int		ind;
	int		i;
	int		*curs;

	if (!stack)
		return (-1);
	i = 1;
	ind = 0;
	curs = stack->start;
	while (i < stack->len)
	{
		if (curs[ind] < curs[i])
			ind = i;
		i++;
	}
	return (ind);
}

/*
** Stackmin/max returns the index of the min/max or -1 if !stack
*/

void	ft_calcrot(int *i, int *k, t_stk **stack)
{
	if (i[0] < stack[0]->len / 2)
		i[1] = i[0];
	else
		i[1] = stack[0]->len - i[0];
	if (k[0] < stack[1]->len / 2)
		k[1] = k[0];
	else
		k[1] = stack[1]->len - k[0];
}

/*
** Sets i/k [1] (new) as the real distance to rotate
*/
