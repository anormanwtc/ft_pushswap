/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:02:25 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 17:24:48 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	dstlen;

	cnt = 0;
	dstlen = ft_strlen(dst);
	if (!dst)
		return (ft_strlen(src));
	if (!src)
		dstsize = (dstsize > ft_strlen(dst) ? ft_strlen(dst) : dstsize);
	if (dstsize < 1)
		return (ft_strlen(src));
	while ((dstlen + cnt) < (dstsize - 1) && src[cnt])
	{
		dst[dstlen + cnt] = src[cnt];
		cnt++;
	}
	if ((dstlen + cnt) < dstsize)
		dst[dstlen + cnt] = '\0';
	if (dstlen > dstsize)
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + dstlen);
}

/*
** only null terminates if there is room as per manual
** only "counts" dstlen up to given dstsize, ie if dstlen > dstsize use dstsize
**
** ft_strlen(NULL) returns (0) without segfaults so it doesnt need protection.
**
** if !dst do nothing and return just ft_strlen(src)
**
** if !src also do nothing
** by moving dstlen to the smaller of (dstlen & ft_strlen(dst))
** thus the smaller + 0 will be returned.
*/
