/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackbigsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:00:24 by anorman           #+#    #+#             */
/*   Updated: 2019/07/24 16:51:52 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_pushplace_a(int *arr, int len, int elem)
{
	int place;
	int i;
	int min;

	i = 0;
	place = 0;
	min = arr[0];
	while (i + 1 < len)
	{
		if (elem > arr[i] && elem < arr[i + 1])
			return (i + 1);
		i++;
		if (arr[i] < min)
		{
			min = arr[i];
			place = i;
		}
	}
	if (elem < arr[0] && elem > arr[len - 1])
		place = 0;
	return (place);
}

/*
** Chooses push location to maintain order.
*/

int				ft_pushplace_b(int *arr, int len, int elem)
{
	int place;
	int i;
	int max;

	i = 0;
	place = 0;
	max = arr[0];
	while (i + 1 < len)
	{
		if (elem < arr[i] && elem > arr[i + 1])
			return (i + 1);
		i++;
		if (arr[i] > max)
		{
			max = arr[i];
			place = i;
		}
	}
	if (elem > arr[0] && elem < arr[len - 1])
		place = 0;
	return (place);
}

static void		st_pa_allordered(t_stk **stack)
{
	int index;

	while (stack[1]->len)
	{
		index = ft_pushplace_a(stack[0]->start, stack[0]->len
				, stack[1]->start[0]);
		ft_rota_to(stack, index);
		ft_stkpush('a', stack);
		write(1, "pa\n", 3);
	}
	ft_rota_to(stack, ft_stackmin(stack[0]));
}

/*
** Pushes all (remaining) from a to b in order.
*/

static void		st_pb_all(t_stk **stack)
{
	int		index;

	while (stack[0]->len > 2)
	{
		index = ft_stackmin(stack[0]);
		if (index == 0)
		{
			ft_stkpush('b', stack);
			write(1, "pb\n", 3);
		}
		else if (index <= stack[0]->len / 2)
		{
			ft_stkrotate('a', stack);
			write(1, "ra\n", 3);
		}
		else if (index > stack[0]->len / 2)
		{
			ft_stkrevtate('a', stack);
			write(1, "rra\n", 4);
		}
	}
}

void			ft_bigsort(t_stk **stacks)
{
	int		opti;
	int		index;

	opti = (stacks[0]->len > 200 ? 50 : 2);
	ft_stkpush('b', stacks);
	ft_stkpush('b', stacks);
	write(1, "pb\npb\n", 6);
	while (stacks[0]->len > opti)
	{
		index = ft_shortest_to_pb(stacks);
		ft_pbindex_inorder(stacks, index);
	}
	st_pb_all(stacks);
	st_pa_allordered(stacks);
}
