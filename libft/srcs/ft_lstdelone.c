/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:31:51 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 15:54:38 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst)
{
	if (alst)
		if (*alst)
		{
			free((*alst)->content);
			(*alst)->content = NULL;
			(*alst)->content_size = 0;
			free(*alst);
			*alst = NULL;
		}
}
