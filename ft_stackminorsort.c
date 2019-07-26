/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:00:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/26 12:26:13 by anorman          ###   ########.fr       */
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
	else if (index > 0)
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
	else if (index > 0)
		while (index--)
		{
			ft_stkrotate('b', stack);
			write(1, "rb\n", 3);
		}
}

void		ft_rotr_num(t_stk **stack, int num, char type)
{
	if (type == 'R')
		while (num++)
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
	int i[3];
	int k[2];
	int moves[2];

	ft_bzero(i, 2);
	moves[0] = -1;
	while (i[0] < stack[0]->len)
	{
		k[0] = ft_pushplace_b(stack[1]->start,
				stack[1]->len, stack[0]->start[i[0]]);
		ft_calcrot(i, k, stack);
		if ((i[0] == i[1] && k[0] == k[1]) || (i[0] != i[1] && k[0] != k[1]))
			moves[1] = (i[1] > k[1] ? i[1] : k[1]);
		else
			moves[1] = i[1] + k[1];
		if (moves[0] == -1 || moves[1] < moves[0])
		{
			moves[0] = moves[1];
			i[2] = i[0];
		}
		i[0]++;
	}
	return (i[2]);
}

/*
** [0] is old, [1] is new, [2] is final
** Returns the index of the one that
** Will take the shortest path to move into place
*/

void		ft_pbindex_inorder(t_stk **stack, int *i)
{
	int		k[2];
	int		common;
	char	type;

	k[0] = ft_pushplace_b(stack[1]->start,
			stack[1]->len, stack[0]->start[i[0]]);
	type = ' ';
	ft_calcrot(i, k, stack);
	common = (i[1] > k[1] ? k[1] : i[1]);
	if (i[0] == i[1] && k[0] == k[1])
		type = 'r';
	else if (i[0] != i[1] && k[0] != k[1])
	{
		common *= -1;
		type = 'R';
	}
	else
		common = 0;
	i[0] -= common;
	k[0] -= common;
	ft_rotr_num(stack, common, type);
	ft_rota_to(stack, i[0]);
	ft_rotb_to(stack, k[0]);
	ft_stkpush('b', stack);
	write(1, "pb\n", 3);
}
/*
** [0] is old, [1] is new, [2] is final
*/
