/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_sortcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:52:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/17 16:26:31 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackcheck(t_stk **stack)
{
	int		*curs;
	int		len;

	if (stack[1]->len)
		return (0);
	if (!(stack[0]->len))
		return (1);
	curs = stack[0]->start;
	len = stack[0]->len;
	while (len--)
	{
		if (curs[0] > curs[1])
			return (0);
		curs++;
	}
	return (1);
}

int		ft_no_dups(t_stk *stack)
{
	int i;
	int k;

	i = 0;
	while (i < stack->len)
	{
		k = i + 1;
		while (k < stack->len)
		{
			if (stack->start[i] == stack->start[k])
			{
				ft_putstr_fd("Error dupicate number ", 2);
				ft_putnbr_fd(stack->start[i], 2);
				ft_putchar_fd('\n', 2);
				return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

char 	**ft_av_split(char *av, int *ac)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_strsplit(av, ' ');
	while (ret[i])
		i++;
	*ac = i;
	return (ret);
}

/*
** For single args separated by spaces
*/

long	ft_basicsort_goal(int len)
{
	long res;

	len--;
	res = 2 * (long)len;
	while (len)
	{
		res += ((long)len / 2);
		len--;
	}
	return (res);
}
