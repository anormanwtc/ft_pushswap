/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:32:34 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:20:02 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		cnt;
	char		*chardst;
	char		*charsrc;

	chardst = (char *)dst;
	charsrc = (char *)src;
	cnt = 0;
	if (dst && src)
	{
		if (dst < src && dst != src)
			ft_memcpy(dst, src, len);
		else if (dst != src)
		{
			while (len > 0)
			{
				chardst[len - 1] = charsrc[len - 1];
				len--;
			}
		}
	}
	return (dst);
}

/*
** My online tests of og memmove showed no safety features.
** My understanding is the only difference between this and memcpy is
** speed vs safety: memcpy has restrict and so doesnt check for changes
** ie memmove can work with overlapping strings but is slightly slower.
*/
