/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/03 18:10:09 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **av1, char **av2)
{
	char *temp;

	temp = *av1;
	*av1 = *av2;
	*av2 = temp;
}

static int	st_checker()
{
	return (0);
}

static int	st_do_argvs(char **av)
{

	return (0);
}

#include <stdio.h>

int			main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	av++;
	st_do_argvs(av);
	return (0);
}
