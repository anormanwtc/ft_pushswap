/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/09/19 17:05:31 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stk	**stack;
	int		split;

	split = 0;
	if (ac-- < 2)
		return (0);
	if (ac == 1 && (split = 1))
		av = ft_av_split(av[1], &ac);
	else
		av++;
	stack = ft_stknew(ac);
	if (!(ft_stackfill(ac, av, stack)) || !ft_no_dups(stack[0]))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_stksort(stack);
	ft_stkdel(stack);
	if (split)
		ft_av_del(av);
	return (0);
}

/*
** Pushswap will choose the order of operations in order to sort the stack
** It does this by sorting the stack and recording what it did.
**
** It starts by taking in arguments, if nothing is given then its finished
** It splits the arguments if it was one space separated string.
**
** It starts by making the stack then filling it and checking for duplicates
** The stackfill also checks for invalid input.
**
** If everything is in order it does the sorting, printing it as it goes.
**
** Then everything that needs it is freed
*/
