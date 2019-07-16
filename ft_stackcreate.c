/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:37:42 by anorman           #+#    #+#             */
/*   Updated: 2019/07/16 12:08:22 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_stk		*ft_stknew(int len)
{
	t_stk *res;

	res = (t_stk *)malloc(sizeof(t_stk));
	res->len = 0;
	res->full = (int *)malloc(sizeof(int) * len);
	res->start = &(res->full[len - 1]);
	return (res);
}

/*
** stknew returns a stack with nothing in it, malloced to len
** start is at end because its empty for now.
** full is for freeing after and the when the stack is full
** (and used in stackfill since start will be full when its filled)
*/

void		ft_stkdel(t_stk *stack)
{
	if (!stack)
		return ;
	free(stack->full);
	free(stack);
}

void		ft_stkprint(t_stk *input)
{
	int i;

	i = input->len;
	while (i--)
	{
		ft_putnbr(*(input->start));
		ft_putchar('\n');
		(input->start)++;
	}
}

int			ft_stackfill(int ac, char **av, t_stk **list)
{
	int i;

	i = 0;
	if (!list || (!(list[0] = ft_stknew(ac))))
		return (0);
	if (!(list[1] = ft_stknew(ac)))
	{
		ft_stkdel(list[0]);
		return (0);
	}
	while (ac-- > 1)
	{
		if (ft_can_atoi(*av) != 1)
		{
			ft_putendl_fd("Error arg contains non number", 2);
			ft_stkdel(list[0]);
			ft_stkdel(list[1]);
			return (0);
		}
		(list[0]->full)[i++] = ft_atoi(*av);
		(list[0]->len)++;
		av++;
	}
	list[0]->start = list[0]->full;
	return (1);
}

/*
** intfill fills all the avs into an int array in t_stk
** Or returns NULL if it cant.
*/
