/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 12:32:33 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_stackcheck(t_stk **stack)
{
	t_stk	*curs;

	if (stack[1] != NULL || !stack[0])
		return (0);
	curs = (stack[0])->next;
	while (curs != stack[0])
	{
		if (curs->val < curs->prev->val)
			return (0);
		curs = curs->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stk	*list[2];

	if (ac < 2)
		return (0);
	av++;
	if (!(list[0] = ft_stackfill(ac, av)))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	list[1] = NULL;
	ft_do_inputs(list);
	if (ft_stackcheck(list))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_stackprint(list[0]);
	ft_stackdel(list[0]);
	ft_stackdel(list[1]);
	return (0);
}
