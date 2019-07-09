/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:53 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 14:22:14 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void		st_comprint(t_list *commands)
{
	char	*cont;

	if (!commands)
		return ;
	while (commands->next)
	{
		cont = (char *)commands->content;
		ft_putendl(cont);
		commands = commands->next;
	}
	cont = (char *)commands->content;
	ft_putendl(cont);
	ft_putchar('\n'); //current format of checker stops at double \n
}

int			main(int ac, char **av)
{
	t_stk	*list;
	t_list	*commands;

	if (ac < 2)
		return (0);
	av++;
	if (!(list = ft_stackfill(ac, av)))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	commands = ft_recursort(list);
	st_comprint(commands);
	ft_stackdel(list);
	return (0);
}
