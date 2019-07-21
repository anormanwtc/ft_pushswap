/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 14:51:00 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stkswap(char ver, t_stk **stacks)
{
	int temp;
	int success;

	if (!stacks)
		return (-1);
	success = 0;
	if ((ver == 'a' || ver == 's') && ++success)
		if (stacks[0]->len > 1)
		{
			temp = *(stacks[0]->start);
			*(stacks[0]->start) = *(stacks[0]->start + 1);
			*(stacks[0]->start + 1) = temp;
		}
	if ((ver == 'b' || ver == 's') && (success += 2))
		if (stacks[1]->len > 1)
		{
			temp = *(stacks[1]->start);
			*(stacks[1]->start) = *(stacks[1]->start + 1);
			*(stacks[1]->start + 1) = temp;
		}
	return (success);
}

/*
** ft_stkswap swaps the nodes based on the version: sa, sb or ss
** -1 for invalid stacks, 1 for a, 2 for b, 3 for both
*/

int		ft_stkrevtate(char ver, t_stk **stacks)
{
	int result;
	int i;
	int temp;

	result = 0;
	if (!stacks)
		return (-1);
	if ((ver == 'a' || ver == 'r') && ++result && stacks[0]->len > 1)
	{
		i = stacks[0]->len;
		temp = stacks[0]->start[stacks[0]->len - 1];
		while (--i > 0)
			*(stacks[0]->start + i) = *(stacks[0]->start + i - 1);
		*(stacks[0]->start) = temp;
	}
	if ((ver == 'b' || ver == 'r') && (result += 2) && stacks[1]->len > 1)
	{
		i = stacks[1]->len;
		*(stacks[1]->start) = stacks[1]->start[stacks[1]->len - 1];
		while (--i + 1 < stacks[1]->len)
			*(stacks[1]->start + i) = *(stacks[1]->start + i - 1);
	}
	return (result);
}

int		ft_stkrotate(char ver, t_stk **stacks)
{
	int result;
	int i;
	int temp;

	result = 0;
	i = -1;
	if (!stacks)
		return (-1);
	if ((ver == 'a' || ver == 'r') && ++result && stacks[0]->len > 1)
	{
		temp = *(stacks[0]->start + i + 1);
		while (++i + 1 < stacks[0]->len)
			*(stacks[0]->start + i) = *(stacks[0]->start + i + 1);
		*(stacks[0]->start + i) = temp;
	}
	if ((ver == 'b' || ver == 'r') && (result += 2) && stacks[1]->len > 1)
	{
		temp = *(stacks[1]->start + i + 1);
		while (++i + 1 < stacks[1]->len)
			*(stacks[1]->start + i) = *(stacks[1]->start + i + 1);
		*(stacks[1]->start + i) = temp;
	}
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

	res = 0;
	if (!stacks)
		return (-1);
	if (ver == 'a' && ++res && stacks[1]->len)
	{
		(stacks[0]->start)--;
		(stacks[0]->len)++;
		*(stacks[0]->start) = *(stacks[1]->start);
		(stacks[1]->start)++;
		(stacks[1]->len)--;
	}
	else if (ver == 'b' && (res += 2) && stacks[0]->len)
	{
		(stacks[1]->start)--;
		(stacks[1]->len)++;
		*(stacks[1]->start) = *(stacks[0]->start);
		(stacks[0]->start)++;
		(stacks[0]->len)--;
	}
	return (res);
}

/*
** ft_stkpush shifts one node to the top stack specifed
** since stackadd puts the new on the bottom, it rotates one too.
** then it deletes the node just shifted.
** -1 for invalid stacks or stackadd failure, 1 for pa, 2 for pb.
** 0 for invalid input
*/

void	ft_do_inputs(t_stk **stacks)
{
	char	*input;
	int		red;
	char	valid;

	valid = 'y';
	while ((red = get_next_line(0, &input)) > 0 && valid > 0 && input[0])
	{
		if (*input == 's' && !input[2])
			valid = ft_stkswap(input[1], stacks);
		else if (*input == 'p' && !input[2])
			valid = ft_stkpush(input[1], stacks);
		else if (*input == 'r' && !input[2])
			valid = ft_stkrotate(input[1], stacks);
		else if (*input == 'r' && input[1] == 'r' && !input[3])
			valid = ft_stkrevtate(input[2], stacks);
		else
			valid = 0;
	}
	if (valid < 1)
		ft_putendl_fd("Error invalid command", 2);
	if (red < 0)
		ft_putendl_fd("Error read failed", 2);
}

/*
** do_inputs reads from stdout and does the relevant function
*/
