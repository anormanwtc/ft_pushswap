/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:37:42 by anorman           #+#    #+#             */
/*   Updated: 2019/07/13 14:11:38 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

/*
** Uses chain lists where you can go both ways and also last->next = start
*/

static t_stk	*st_stacknew(int val)
{
	t_stk	*start;

	if (!(start = (t_stk *)malloc(sizeof(t_stk))))
		return (NULL);
	start->val = val;
	start->next = start;
	start->prev = start;
	return (start);
}

/*
** Starts a new stack, only used if you stackadd to NULL
*/

t_stk	*ft_stackadd(t_stk *start, int val)
{
	t_stk	*new;
	if (!start)
		return (st_stacknew(val));
	if (!(new = st_stacknew(val)))
	{
		ft_stackdel(start);
		return (NULL);
	}
	start->prev->next = new;
	new->prev = start->prev;
	start->prev = new;
	new->next = start;
	return (new);
}

/*
** Adds a new node with val to the stack
** Take the return to make the added be on the top
** Leave the return to keep it at the back.
*/

void	ft_stackdel(t_stk *start)
{
	t_stk	*temp;

	if (start)
	{
		temp = start->next;
		while (temp != start)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(start);
	}
}

/*
** Deletes the whole stack
*/

void	ft_stackrem(t_stk **node)
{
	t_stk *temp;

	if (*node != (*node)->next)
		temp = (*node)->next;
	else
		temp = NULL;
	(*node)->next->prev = (*node)->prev;
	(*node)->prev->next = (*node)->next;
	free(*node);
	*node = temp;
}

/*
** Removes a node and links the others back up
** sets the given to next for if it was the start and next is different.
** If the chain is just 1 node then its set to null.
*/

void	ft_stackprint(t_stk *start)
{
	t_stk	*temp;

	if (!start)
		return ;
	temp = start->prev;
	while (temp != start)
	{
		ft_putnbr(start->val);
		ft_putchar('\n');
		start = start->next;
	}
	ft_putnbr(start->val);
}
