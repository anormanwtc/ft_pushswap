/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:19:48 by anorman           #+#    #+#             */
/*   Updated: 2019/07/09 14:20:06 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_stackcheck(t_stk **stack)
{
	t_stk	*curs;

	if (stack[1])
		return (0);
	if (!stack[0])
		return (1);
	curs = (stack[0])->next;
	while (curs != stack[0])
	{
		if (curs->val < curs->prev->val)
			return (0);
		curs = curs->next;
	}
	return (1);
}
