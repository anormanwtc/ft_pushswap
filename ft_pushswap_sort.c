/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:20:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/13 13:57:51 by anorman          ###   ########.fr       */
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

	ft_stkswap('a', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
		ft_lstadd(&replace, ft_lstnew("sa", 3));
	old = replace;
	ft_stkswap('a', stack);
	ft_stkswap('b', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("sb", 3));
		old = replace;
	}
	ft_stkswap('b', stack);
	ft_stkswap('s', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("ss", 3));
		old = replace;
	}
	ft_stkswap('s', stack);
	return (old);
}

t_list			*st_recurpush(t_stk **stack, long steps)
{
	t_list	*old;
	t_list	*replace;
	int		didpush;

	didpush = ft_stkpush('a', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
		ft_lstadd(&replace, ft_lstnew("pa", 3));
	old = replace;
	if (didpush)
		ft_stkpush('b', stack);
	didpush = ft_stkpush('b', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("pb", 3));
		old = replace;
	}
	if (didpush)
		ft_stkpush('a', stack);
	return (old);
}

t_list			*st_recur_rot(t_stk **stack, long steps)
{
	t_list	*old;
	t_list	*replace;

	ft_stkrotate('a', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
		ft_lstadd(&replace, ft_lstnew("ra", 3));
	old = replace;
	ft_stkrotate('A', stack);
	ft_stkrotate('b', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rb", 3));
		old = replace;
	}
	ft_stkrotate('B', stack);
	ft_stkrotate('r', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rr", 3));
		old = replace;
	}
	ft_stkrotate('R', stack);
	return (old);
}

t_list			*st_recur_rrot(t_stk **stack, long steps)
{
	t_list	*old;
	t_list	*replace;

	ft_stkrotate('A', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
		ft_lstadd(&replace, ft_lstnew("rra", 4));
	old = replace;
	ft_stkrotate('a', stack);
	ft_stkrotate('B', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rrb", 4));
		old = replace;
	}
	ft_stkrotate('b', stack);
	ft_stkrotate('R', stack);
	if ((replace = ft_recursort(stack, steps + 1)))
	{
		ft_lstdel(&old);
		ft_lstadd(&replace, ft_lstnew("rrr", 4));
		old = replace;
	}
	ft_stkrotate('r', stack);
	return (old);
}

/*
** Each recur one will recursively do the thing and then undo it to try the next
** Each goes through each chain, success will decrease the goal inside recursort
** So the last success will be the fastest.
*/

t_list			*ft_recursort(t_stk **stack, long steps)
{
	t_list		*old;
	t_list		*replace;
	static long	goal;

	if (!goal)
		goal = ft_basicsort_goal(ft_stacklen(stack[0])) + 1;
	old = NULL;
	if (ft_stackcheck(stack))
	{
		goal = steps - 1;
		return (ft_lstnew(NULL, 0));
	}
	if (steps < goal)
	{
		replace = st_recurswap(stack, steps);
		old = replace;
		if ((replace = st_recurpush(stack, steps)))
			ft_lstreplace(old, replace);
		if ((replace = st_recur_rot(stack, steps)))
			ft_lstreplace(old, replace);
		if ((replace = st_recur_rrot(stack, steps)))
			ft_lstreplace(old, replace);
	}
	return (old);
}
