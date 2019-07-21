/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:00:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 17:59:58 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rota_to(t_stk **stack, int index)
{
	if (index > stack[0]->len / 2)
	{
		index = stack[0]->len - index;
		while (index--)
		{
			ft_stkrevtate('a', stack);
			write(1, "rra\n", 4);
		}
	}
	else
		while (index--)
		{
			ft_stkrevtate('a', stack);
			write(1, "ra\n", 3);
		}
}

void		ft_rotb_to(t_stk **stack, int index)
{
	if (index > stack[1]->len / 2)
	{
		index = stack[1]->len - index;
		while (index--)
		{
			ft_stkrevtate('b', stack);
			write(1, "rrb\n", 4);
		}
	}
	else
		while (index--)
		{
			ft_stkrevtate('a', stack);
			write(1, "rb\n", 3);
		}
}
