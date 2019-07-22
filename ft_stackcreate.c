/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:37:42 by anorman           #+#    #+#             */
/*   Updated: 2019/07/22 17:17:56 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk		**ft_stknew(int len)
{
	t_stk **res;

	res = (t_stk **)malloc(sizeof(t_stk *));
	res[0] = (t_stk *)malloc(sizeof(t_stk));
	res[0]->len = 0;
	res[0]->full = (int *)malloc(sizeof(int) * len);
	res[0]->start = &(res[0]->full[len]);
	res[1] = (t_stk *)malloc(sizeof(t_stk));
	res[1]->len = 0;
	res[1]->full = (int *)malloc(sizeof(int) * len);
	res[1]->start = &(res[1]->full[len]);
	return (res);
}

/*
** stknew returns a stack with nothing in it, malloced to len
** start is at end because its empty for now.
** full is for freeing after and the when the stack is full
** (and used in stackfill since start will be full when its filled)
*/

void		ft_stkdel(t_stk **stack)
{
	if (!stack)
		return ;
	free(stack[0]->full);
	free(stack[0]);
	stack[0] = NULL;
	free(stack[1]->full);
	free(stack[1]);
	stack[1] = NULL;
}

void		ft_stkprint(t_stk **input)
{
	int i;

	ft_putstr("Stack 1:\n");
	i = input[0]->len;
	while (i--)
	{
		ft_putnbr(*(input[0]->start));
		ft_putchar('\n');
		(input[0]->start)++;
	}
	ft_putstr("Stack 2:\n");
	i = input[1]->len;
	while (i--)
	{
		ft_putnbr(*(input[1]->start));
		ft_putchar('\n');
		(input[1]->start)++;
	}
}

int			ft_stackfill(int ac, char **av, t_stk **list)
{
	int i;

	i = 0;
	if (!list)
		return (0);
	while (ac-- > 0 && *av)
	{
		if (ft_can_atoi(*av) != 1)
		{
			ft_putendl_fd("Error arg contains non integer", 2);
			return (0);
		}
		(list[0]->full)[i++] = ft_atoi(*av);
		(list[0]->start)--;
		(list[0]->len)++;
		av++;
	}
	return (1);
}

/*
** intfill fills all the avs into an int array in t_stk
** Or returns NULL if it cant.
*/
