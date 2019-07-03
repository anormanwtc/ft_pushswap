/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:36:58 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 17:09:29 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cnt;

	cnt = 0;
	if (dst && src)
	{
		while (src && src[cnt] != '\0' && cnt < len)
		{
			dst[cnt] = src[cnt];
			cnt++;
		}
		while (cnt < len)
		{
			dst[cnt] = '\0';
			cnt++;
		}
	}
	return (dst);
}

/*
** dst remaining len filled with '\0'
** no termination if len is insificiant (as per the manual)
*/
