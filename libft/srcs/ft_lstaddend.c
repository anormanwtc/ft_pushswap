/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:37:58 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:04:23 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		if (!*alst && new)
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}
