/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_sortcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 14:13:19 by anorman          ###   ########.fr       */
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
			{
				ft_putstr_fd("Error dupicate number ", 2);
				ft_putnbr_fd(stack->start[i], 2);
				ft_putchar_fd('\n', 2);
				return (0);
			}
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
		if (curs[ind] > curs[i + 1])
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
