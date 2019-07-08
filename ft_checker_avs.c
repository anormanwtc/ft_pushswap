/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/08 14:26:33 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static int		st_swap(char ver, t_stk **stacks)
{
	int temp;
	int success;
	
	if (!stacks)
		return (-1);
	success = 0;
	if ((ver == 'a' || ver == 's') && stacks[0])
	{
		temp = (stacks[0])->val;
		(stacks[0])->val = (stacks[0])->next->val;
		(stacks[0])->next->val = temp;
		success++;
	}
	if ((ver == 'b' || ver == 's') && stacks[1])
	{
		temp = (stacks[1])->val;
		(stacks[1])->val = (stacks[1])->next->val;
		(stacks[1])->next->val = temp;
		success += 2;
	}
	return (success);
}

/*
** st_swap swaps the nodes based on the version: sa, sb or ss
** -1 for invalid stacks, 1 for a, 2 for b, 3 for both
*/

static int		st_rotate(char ver, t_stk **stacks)
{
	int result;

	result = 0;
	if (!stacks)
		return (-1);
	if ((ver == 'a' || ver == 'r') && stacks[0] && ++result)
		(stacks[0]) = (stacks[0])->next;
	if ((ver == 'b' || ver == 'r') && stacks[1] && (result += 2))
		(stacks[1]) = (stacks[1])->next;
	if ((ver == 'A' || ver == 'R') && stacks[0] && ++result)
		(stacks[0]) = (stacks[0])->prev;
	if ((ver == 'B' || ver == 'R') && stacks[1] && (result += 2))
		(stacks[1]) = (stacks[1])->prev;
	return (result);
}

/*
** st_rotate shifts the starts based on the version: ra, rb, rr
** capitals for reverse rotation, the caller should convert.
** -1 for invalid stacks, 1 for a, 2 for b, 3 for both
*/

static int		st_push(char ver, t_stk **stacks)
{
	if (!stacks)
		return (-1);
	if (ver == 'a' && stacks[1])
	{
		if (!(ft_stackadd(stacks[0], (stacks[1])->val)))
			return (-1);
		stacks[0] = (stacks[0])->prev;
		ft_stackrem(stacks + 1);
		return (1);
	}
	if (ver == 'b' && stacks[0])
	{
		if (!(ft_stackadd(stacks[1], (stacks[0])->val)))
			return (-1);
		stacks[0] = (stacks[0])->prev;
		ft_stackrem(stacks);
		return (2);
	}
	return (0);
}

/*
** st_push shifts one node to the top stack specifed
** since stackadd puts the new on the bottom, it rotates one too.
** then it deletes the node just shifted.
** -1 for invalid stacks or stackadd failure, 1 for pa, 2 for pb.
*/

void			ft_do_inputs(t_stk **stacks)
{
	char	*input;
	int		red;
	char	valid;

	valid = 'y';
	while ((red = get_next_line(1, &input)) > 0 && valid > 0)
	{
		if (*input == 's')
			valid = st_swap(input[1], stacks);
		else if (*input == 'p')
			valid = st_push(input[1], stacks);
		else if (*input == 'r' && !input[2])
			valid = st_rotate(input[1], stacks);
		else if (*input == 'r')
			valid = st_rotate(ft_toupper(input[2]), stacks);
		else
			valid = 0;
	}
	if (valid < 1)
		ft_putstr_fd("Error invalid command", 2);
	if (red < 0)
		ft_putstr_fd("Error read failed", 2);
}


t_stk			*ft_stackfill(int ac, char **av)
{
	t_stk	*list;

	list = NULL;
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

/*
** Stackfill fills all the avs into an int chain or returns NULL if it cant.
*/
