/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/07/17 16:29:39 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		st_revcomprint(t_list *commands)
{
	char	*cont;

	if (!commands)
		return ;
	st_comprint(commands->next);
	cont = (char *)commands->content;
	ft_putendl(cont);
	ft_putchar('\n'); //current format of checker stops at double \n
}

/*
** Recursively does the chain so its reverse order but quick
*/

static void	st_comprint(t_list *commands)
{
	char *cont;

	if (!commands)
		return ;
	while (commands)
	{
		cont = (char *)commands->content;
		ft_putendl(cont);
		commands = commands->next;
	}
	ft_putchar('\n');
}

/*
** Prints in standard order
*/

int			main(int ac, char **av)
{
	t_stk	**stack;
	t_list	*commands;

	if (ac-- < 2)
		return (0);
	if (ac == 1)
		av = ft_av_split(av, &ac);
	av++;
	stack = ft_stknew(ac, av);
	if (!(ft_stackfill(ac, av, stack)) || !ft_no_dups(stack[0]))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	stack[1] = NULL;
//	ft_stackprint(stack);
	st_comprint(commands);
	ft_stackdel(stack);
	return (0);
}
