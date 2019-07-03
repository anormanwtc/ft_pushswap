/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:02:29 by anorman           #+#    #+#             */
/*   Updated: 2019/06/21 12:57:42 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst)
{
	if (lst)
	{
		if (*lst)
		{
			if ((*lst)->next)
				ft_lstdel(&((*lst)->next));
			ft_lstdelone(lst);
		}
		*lst = NULL;
	}
}

/*
** I changed lst_delone to not take function del and
** DIY the deleting of lst->content
** as such, make sure lst->content is freeable
** or use my listnew which duplicates the given and so is freeable
*/
