/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/13 14:27:48 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

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
	sleep(10);
	return (0);
}
