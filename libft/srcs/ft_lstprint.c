/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:52 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:11:57 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, char *space)
{
	while (lst)
	{
		ft_putstr(lst->content);
		if (space && *space)
			ft_putchar(*space);
		lst = lst->next;
	}
}
