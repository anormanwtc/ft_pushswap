/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:21:09 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 17:14:17 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	cnt;

	if (!s)
		return (NULL);
	if (!(substr = (char *)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	cnt = 0;
	while (cnt < len && s[cnt + (size_t)start])
	{
		substr[cnt] = s[cnt + (size_t)start];
		cnt++;
	}
	substr[cnt] = '\0';
	return (substr);
}

/*
** if start and len arent valid -> behaviour undefined
** as such I neglected to check for the end of input s
*/
