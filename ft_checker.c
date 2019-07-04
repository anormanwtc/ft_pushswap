/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/04 16:23:47 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void		st_swap(char ver, t_stk **stacks)
{
	int temp;

	if (ver == 'a' || ver == 's')
	{
		temp = (stacks[0])->val;
		(stacks[0])->val = (stacks[0])->prev->val;
		(stacks[0])->prev->val = temp;
	}
	if (ver == 'b' || ver == 's')
	{
		temp = (stacks[1])->val;
		(stacks[1])->val = (stacks[1])->prev->val;
		(stacks[1])->prev->val = temp;
	}
}

static t_stk	*st_fill(int ac, char **av, t_stk *list)
{
	while (ac-- > 1)
	{
		if (ft_can_atoi(*av) != 1)
		{
			ft_stackdel(list);
			return (NULL);
		}
		list = ft_stackadd(list, ft_atoi(*av));
		av++;
	}
	return (list);
}

static int		st_do_argvs(t_stk **stacks)
{
	char	*str;
	char	*temp;
	int		red;
	int		i;

	str = (char *)malloc(BUFF + 1);
	while ((red = read(1, str, BUFF)) > 0)
	{
		str[red] = '\0';
		i = 0;
		while (str[i] != 's' && str[i] != 'p' && str[i] != 'r')
			i++;
		if (str[i++] == 's')
			st_swap(str[i++], stacks);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_stk	*list;

	list = NULL;
	if (ac < 2)
		return (0);
	av++;
	if (!(list = st_fill(ac, av, list)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_stackprint(list);
	return (0);
}
