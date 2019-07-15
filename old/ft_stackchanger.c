/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackchanger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/15 14:23:51 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_stkswap(char ver, t_stk **stacks)
{
	int temp;
	int success;
	
	if (!stacks)
		return (-1);
	success = 0;
	if ((ver == 'a' || ver == 's') && ++success)
		if (stacks[0])
		{
			temp = (stacks[0])->val;
			(stacks[0])->val = (stacks[0])->next->val;
			(stacks[0])->next->val = temp;
		}
	if ((ver == 'b' || ver == 's') && (success += 2))
		if (stacks[1])
		{
			temp = (stacks[1])->val;
			(stacks[1])->val = (stacks[1])->next->val;
			(stacks[1])->next->val = temp;
		}
	return (success);
}

/*
** ft_stkswap swaps the nodes based on the version: sa, sb or ss
** -1 for invalid stacks, 1 for a, 2 for b, 3 for both
*/

int		ft_stkrotate(char ver, t_stk **stacks)
{
	int result;

	result = 0;
	if (!stacks)
		return (-1);
	if ((ver == 'a' || ver == 'r') && ++result && stacks[0])
		(stacks[0]) = (stacks[0])->next;
	if ((ver == 'b' || ver == 'r') && (result += 2) && stacks[1])
		(stacks[1]) = (stacks[1])->next;
	if ((ver == 'A' || ver == 'R') && ++result && stacks[0])
		(stacks[0]) = (stacks[0])->prev;
	if ((ver == 'B' || ver == 'R') && (result += 2) && stacks[1])
		(stacks[1]) = (stacks[1])->prev;
	return (result);
}

/*
** ft_stkrotate shifts the starts based on the version: ra, rb, rr
** capitals for reverse rotation, the caller should convert.
** -1 for invalid stacks, 1 for a, 2 for b, 3 for both
*/

int		ft_stkpush(char ver, t_stk **stacks)
{
	int	res;

	res = 3;
	if (!stacks)
		return (-1);
	if (ver == 'a' && stacks[1] && ++res)
	{
		if (!(stacks[0] = ft_stackadd(stacks[0], (stacks[1])->val)))
			return (-1);
		ft_stackrem(stacks + 1);
	}
	else if (ver == 'b' && stacks[0] && (res += 2))
	{
		if (!(stacks[1] = ft_stackadd(stacks[1], (stacks[0])->val)))
			return (-1);
		ft_stackrem(stacks);
	}
	else
		return (0);
	return (res);
}

/*
** ft_stkpush shifts one node to the top stack specifed
** since stackadd puts the new on the bottom, it rotates one too.
** then it deletes the node just shifted.
** -1 for invalid stacks or stackadd failure, 1 for pa, 2 for pb.
** 3 for did nothing either by nothing in the stack
** 0 for invalid input
*/

void	ft_do_inputs(t_stk **stacks)
{
	char	*input;
	int		red;
	char	valid;

	valid = 'y';
	while ((red = get_next_line(1, &input)) > 0 && valid > 0 && input[0])
	{
		if (*input == 's' && !input[2])
			valid = ft_stkswap(input[1], stacks);
		else if (*input == 'p' && !input[2])
			valid = ft_stkpush(input[1], stacks);
		else if (*input == 'r' && !input[2])
			valid = ft_stkrotate(input[1], stacks);
		else if (*input == 'r' && !input[3])
			valid = ft_stkrotate(ft_toupper(input[2]), stacks);
		else
			valid = 0;
	}
	if (valid < 1)
		ft_putendl_fd("Error invalid command", 2);
	if (red < 0)
		ft_putendl_fd("Error read failed", 2);
}


t_stk	*ft_stackfill(int ac, char **av)
{
	t_stk	*list;

	list = NULL;
	if (ac-- > 1)
	{
		if (ft_can_atoi(*av) != 1)
		{
			ft_putendl_fd("Error arg contains non number", 2);
			ft_stackdel(list);
			return (NULL);
		}
		list = ft_stackfill(ac, av + 1);
		list = ft_stackadd(list, ft_atoi(*av));
		av++;
	}
	return (list);
}

/*
** Stackfill fills all the avs into an int chain or returns NULL if it cant.
*/
