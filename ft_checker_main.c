/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/17 12:23:19 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static char 	**st_av_split(char *av, int *ac)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_strsplit(av, ' ');
	while (ret[i])
		i++;
	*ac = i + 1;
	return (ret);
}

/*
** For single arg separated by spaces
*/

int				main(int ac, char **av)
{
	t_stk	**list;

	if (ac < 2)
		return (0);
	av++;
	list = ft_stknew(--ac);
	if (ac == 1)
		av = st_av_split(av[0], &ac);
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
	ft_stkprint(list);
	ft_stkdel(list);
//	sleep(10);
	return (0);
}
