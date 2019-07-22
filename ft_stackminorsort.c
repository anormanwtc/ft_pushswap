/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:00:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/22 17:18:36 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rota_to(t_stk **stack, int index)
{
	if (index > stack[0]->len / 2)
	{
		index = stack[0]->len - index;
		while (index--)
		{
			ft_stkrevtate('a', stack);
			write(1, "rra\n", 4);
		}
	}
	else
		while (index--)
		{
			ft_stkrotate('a', stack);
			write(1, "ra\n", 3);
		}
}

void		ft_rotb_to(t_stk **stack, int index)
{
	if (index > stack[1]->len / 2)
	{
		index = stack[1]->len - index;
		while (index--)
		{
			ft_stkrevtate('b', stack);
			write(1, "rrb\n", 4);
		}
	}
	else
		while (index--)
		{
			ft_stkrotate('a', stack);
			write(1, "rb\n", 3);
		}
}

void		ft_rotr_num(t_stk **stack, int num, char type)
{
	if (type == 'R')
		while (num--)
		{
			ft_stkrevtate('r', stack);
			write(1, "rrr\n", 4);
		}
	else
		while (num--)
		{
			ft_stkrotate('r', stack);
			write(1, "rr\n", 3);
		}
}

int			ft_shortest_to_pb(t_stk **stack)
{
	int i;
	int k;
	int best;
	int index;
	int moves;

	i = 0;
	best = -1;
	while (i < stack[0]->len)
	{
		k = ft_pushplace(stack[1]->start, stack[1]->len, stack[0]->start[i]);
		if (i < stack[0]->len / 2 && k < stack[1]->len)
			moves = (i > k ? i - k : k - i);
		else if (i >= stack[0]->len / 2 && k >= stack[1]->len)
			moves = (i > k ? i - k : k - i);
		else
			moves = i + k;
		if (best == -1 || moves < best)
		{
			best = moves;
			index = i;
		}
	}
	return (index);
}

/*
** Returns the index of the one that
** Will take the shortest path to move into place
*/

void		ft_pbindex_inorder(t_stk **stack, int i)
{
	int		k;
	int		common;
	char	type;

	k = ft_pushplace(stack[1]->start, stack[1]->len, stack[0]->start[i]);
	type = ' ';
	if (i < stack[0]->len / 2 && k < stack[1]->len)
	{
		common = (i > k ? i - k : k - i);
		type = 'r';
	}
	else if (i >= stack[0]->len / 2 && k >= stack[1]->len)
	{
		common = (i > k ? i - k : k - i);
		type = 'R';
	}
	else
		common = 0;
	i -= common;
	k -= common;
	ft_rotr_num(stack, common, type);
	ft_rota_to(stack, i);
	ft_rotb_to(stack, k);
}
