/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:37:55 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:46:37 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	cnt;
	size_t	cnt2;

	if (!s1 && !s2)
		return (NULL);
	cnt = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(cnt * (sizeof(char) + 1))))
		return (NULL);
	cnt = 0;
	while (s1 && s1[cnt])
	{
		res[cnt] = s1[cnt];
		cnt++;
	}
	cnt2 = 0;
	while (s2 && s2[cnt2])
	{
		res[cnt + cnt2] = s2[cnt2];
		cnt2++;
	}
	res[cnt + cnt2] = '\0';
	return (res);
}

/*
** I only check for !s1 && !s2 in the start so (Null x Null) = Null
** and (Null x thing) = thing and (thing x Null) = thing
**
** ft_strlen protects itself and returns 0 for Null strings
**
** This way I check in my while loops and Null joins to something to make
** something (ie just the existing part stays)
*/
