/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/07/16 16:29:15 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

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
	t_stk	*stack[2];
	t_list	*commands;

	if (ac < 2)
		return (0);
	av++;
	if (!(stack[0] = ft_stackfill(ac, av)))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	stack[1] = NULL;
//	ft_stackprint(stack[0]);
//	ft_putchar('\n');
//	ft_stackprint(stack[1]);
	st_comprint(commands);
	ft_stackdel(stack[0]);
	ft_stackdel(stack[1]);
	return (0);
}
