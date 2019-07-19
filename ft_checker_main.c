/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/19 17:15:26 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	t_stk	**list;

	if (ac-- < 2)
		return (0);
	av++;
	if (ac == 1)
		av = ft_av_split(av[0], &ac);
	list = ft_stknew(ac);
	if (ft_stackfill(ac, av, list) && ft_no_dups(list[0]))
	{
		ft_do_inputs(list);
		if (ft_stackcheck(list))
			ft_putendl("OK");
		else
			ft_putendl("KO");
		ft_stkprint(list);
	}
	else
		ft_putendl_fd("Error stack creation failed", 2);
	ft_stkdel(list);
	return (0);
}
