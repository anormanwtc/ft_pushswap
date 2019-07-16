/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/16 16:22:52 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		main(int ac, char **av)
{
	t_stk	*list[2];
	int		i;

	if (ac < 2)
		return (0);
	av++;
	/*if (ac == 2)
	{
		av = ft_strsplit(*av, ' ');
		i = 0;
		while (av[i])
			i++;
		ac = i + 1;
	} "for single arg separated by spaces"*/
	if (!ft_stackfill(ac, av, list))
	{
		ft_putendl_fd("Error stack creation failed", 2);
		return (0);
	}
	ft_do_inputs(list);
	if (ft_stackcheck(list))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_putendl("Stack 1:");
	ft_stkprint(list[0]);
	ft_putchar('\n');
	ft_putendl("Stack 2:");
	ft_stkprint(list[1]);
	ft_stkdel(list[0]);
	ft_stkdel(list[1]);
//	sleep(10);
	return (0);
}
