/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackbigsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:00:24 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 17:59:37 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		st_pushplace_a(int *arr, int len, int elem)
{
	int place;
	int i;

	i = 0;
	place = 0;
	if (len == 2 && elem > arr[0] && elem < arr[1])
		place = 1;
	else if (len == 2 && elem < arr[0] && elem > arr[1])
		place = 0;
	else
		while (i + 1 < len)
		{
			if (elem > arr[i] && elem < arr[i + 1])
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (place);
}

/*
** Pushes all back to a in order.
*/

static void		st_pa_allordered(t_stk **stack)
{
	int index;

	while (stack[1]->len)
	{
		index = st_pushplace_a(stack[0]->start, stack[0]->len
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
//	t_list	*best;
//	int		opti;

//	opti = stacks[0]->len / 4;
	ft_stkpush('b', stacks);
	ft_stkpush('b', stacks);
//	while (stack[0]->len > opti)
//	{
//		best = ibest_from_a2b(stack);///
//		ft_optimoves(&best);
//		process_moves; //
//		ft_stkpush('b', stacks);
//		//free_moves?
//	}
	st_pb_all(stacks);
	st_pa_allordered(stacks);
}
		

