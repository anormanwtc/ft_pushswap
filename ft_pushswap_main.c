/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 17:47:27 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void		st_revcomprint(t_list *commands)
{
	char	*cont;

	if (!commands)
		return ;
	cont = (char *)commands->content;
	ft_putendl(cont);
	ft_putchar('\n'); 
}
*/
/*
** Recursively does the chain so its reverse order but quick
** current format of checker stops at double \n
*/
/*
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
*/
/*
** Prints in standard order
** current format of checker stops at double \n
*/

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
	stack[1] = NULL;
	ft_stkdel(stack);
	return (0);
}
