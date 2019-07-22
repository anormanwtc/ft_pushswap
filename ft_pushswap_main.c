/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/07/22 16:55:55 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stk	**stack;

	if (ac-- < 2)
		return (0);
	if (ac == 1)
		av = ft_av_split(av[1], &ac);
	else
		av++;
	stack = ft_stknew(ac);
	if (!(ft_stackfill(ac, av, stack)) || !ft_no_dups(stack[0]))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	ft_stksort(stack);
	ft_stkdel(stack);
	return (0);
}
