/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:34:43 by anorman           #+#    #+#             */
/*   Updated: 2019/06/18 17:18:09 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstcat(t_list *lst)
{
	t_list			*temp;
	unsigned long	sumsize;
	char			*str;

	temp = lst;
	sumsize = 0;
	while (temp)
	{
		sumsize = sumsize + (unsigned long)temp->content_size;
		temp = temp->next;
	}
	if (!(str = malloc((sumsize + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(str, sumsize + 1);
	while (lst)
	{
		ft_strcat(str, (char *)lst->content);
		lst = lst->next;
	}
	return (str);
}

/*
** ft_lstcat requires null terminated content.
** I may consider doing ft_lstmemcat
**
** ft_lstcat returns an empty string if !lst as NULL is for malloc fail
*/
