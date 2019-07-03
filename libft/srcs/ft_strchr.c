/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:26:37 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:36:42 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt] != '\0')
		{
			if (s[cnt] == c)
				return ((char *)&s[cnt]);
			cnt++;
		}
		if (s[cnt] == c)
			return ((char *)&s[cnt]);
	}
	return (NULL);
}
