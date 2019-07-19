/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:00:33 by anorman           #+#    #+#             */
/*   Updated: 2019/07/19 13:21:46 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*ft_short_rot_a(t_stk **stack, int index);
{
	t_list	*commands;

	commands = NULL;
	if (index > stack->len / 2)
	{
		index = stack-len - index;
		while (index--)
		{
			ft_lstadd(commands, ft_lstnew("rra", 4));
			ft_stkrevtate('a', stack);
		}
	}
	else
		while (index--)
		{
			ft_lstadd(commands, ft_lstnew("ra", 3));
			ft_stkrevtate('a', stack);
		}
	return (commands);
}


