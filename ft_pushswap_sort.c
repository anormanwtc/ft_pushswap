/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:20:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/14 12:25:12 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

/*
** Each recur one will recursively do the thing and then undo it to try the next
** Each goes through each chain, success will decrease the goal inside recursort
** So the last success will be the fastest.
*/

t_list			*st_recurswap(t_stk **stack, long steps)
{
	t_list	*old;
	t_list	*replace;

	ft_stkswap('s', stack);
	if ((replace = ft_recursort(stack, steps + 1, 's')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("ss", 3));
		old = replace;
	}
	ft_stkswap('s', stack);
	ft_stkswap('a', stack);
	if ((replace = ft_recursort(stack, steps + 1, 's')))
		ft_lstadd(&replace, ft_lstnew("sa", 3));
	old = replace;
	ft_stkswap('a', stack);
	ft_stkswap('b', stack);
	if ((replace = ft_recursort(stack, steps + 1, 's')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("sb", 3));
		old = replace;
	}
	ft_stkswap('b', stack);
	return (old);
}

/*
** Any two swaps in a row will not be the best path
*/

t_list			*st_recurpush(t_stk **stack, long steps, char prev)
{
	t_list	*old;
	t_list	*replace;
	int		didpush;

	old = NULL;
	if (prev != 'P')
	{
		didpush = ft_stkpush('a', stack);
		if (didpush && (replace = ft_recursort(stack, steps + 1, 'p')))
			ft_lstadd(&replace, ft_lstnew("pa", 3));
		old = replace;
		if (didpush)
			ft_stkpush('b', stack);
	}
	if (prev != 'p')
	{
		didpush = ft_stkpush('b', stack);
		if (didpush && (replace = ft_recursort(stack, steps + 1, 'P')))
		{
			ft_lstadd(&replace, ft_lstnew("pb", 3));
			ft_lstreplace(&old, replace);
			ft_stkpush('a', stack);
		}
	}
	return (old);
}

/*
** 'p' signifies "pa"; 'P' signifies "pb"
** pa pb or pb pa is useless and so skipped.
*/

t_list			*st_recur_rot(t_stk **stack, long steps, char prev)
{
	t_list	*old;
	t_list	*replace;

	ft_stkrotate('r', stack);
	if ((replace = ft_recursort(stack, steps + 1, 'r')))
		ft_lstadd(&replace, ft_lstnew("rr", 3));
	old = replace;
	ft_stkrotate('R', stack);
	ft_stkrotate('a', stack);
	if (prev != 'A' && (replace = ft_recursort(stack, steps + 1, 'a')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("ra", 3));
		old = replace;
	}
	ft_stkrotate('A', stack);
	ft_stkrotate('b', stack);
	if (prev != 'B' && (replace = ft_recursort(stack, steps + 1, 'b')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rb", 3));
		old = replace;
	}
	ft_stkrotate('B', stack);
	return (old);
}

/*
** 'a' signifies "ra"; 'A' signifies "rra"
** ra rra or rb rrb is useless and so skipped
** rr rrr is also useless but line limits...
*/

t_list			*st_recur_rrot(t_stk **stack, long steps, char prev)
{
	t_list	*old;
	t_list	*replace;

	ft_stkrotate('R', stack);
	if ((replace = ft_recursort(stack, steps + 1, 'R')))
		ft_lstadd(&replace, ft_lstnew("rrr", 4));
	old = replace;
	ft_stkrotate('r', stack);
	ft_stkrotate('A', stack);
	if (prev != 'a' && (replace = ft_recursort(stack, steps + 1, 'A')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rra", 4));
		old = replace;
	}
	ft_stkrotate('a', stack);
	ft_stkrotate('B', stack);
	if (prev != 'b' && (replace = ft_recursort(stack, steps + 1, 'B')))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rrb", 4));
		old = replace;
	}
	ft_stkrotate('b', stack);
	return (old);
}

/*
** Like above 'B' signifies "rrb"; 'b' signifies "rb"
** Also in both the rotation is done then undone without checking prev
** line limits... Its also fast anyway so no big deal
*/

/*
** Each recur one will recursively do the thing and then undo it to try the next
** Each goes through each chain, success will decrease the goal inside recursort
** So the last success will be the fastest.
*/

t_list			*ft_recursort(t_stk **stack, long steps, char prev)
{
	t_list		*old;
	t_list		*replace;
	static long	goal;

	if (!goal)
		goal = ft_basicsort_goal(ft_stacklen(stack[0])) + 1;
	old = NULL;
	if (ft_stackcheck(stack))
	{
		goal = steps;
		return (ft_lstnew(NULL, 0));
	}
	if (steps < goal)
	{
		if ((prev != 's' && (replace = st_recurswap(stack, steps))))
			ft_lstreplace(&old, replace);
		if ((replace = st_recurpush(stack, steps, prev)))
			ft_lstreplace(&old, replace);
		if ((replace = st_recur_rot(stack, steps, prev)))
			ft_lstreplace(&old, replace);
		if ((replace = st_recur_rrot(stack, steps, prev)))
			ft_lstreplace(&old, replace);
	}
	return (old);
}

/*
** If the previous command was s
** Doing another sx will undo what is done or just be a worse ss
**
** pa pb does nothing and will be ignored too
** though pa pa and pb pb is valid
**
** If the previous was r/R then we dont want to do the opposite rotation
** ra rrb and similar is potentially valid though
** Similarily ra rb is just worse rr
**
** Since push/rotate have some valid repeats they will get given prev to decide
** inside themselves
*/
