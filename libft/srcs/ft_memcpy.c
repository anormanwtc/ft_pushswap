/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:33:34 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:18:36 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cnt;
	char		*chardst;
	const char	*charsrc;

	cnt = 0;
	chardst = (char *)dst;
	charsrc = (const char *)src;
	if (dst && src)
		while (cnt < n && dst != src)
		{
			chardst[cnt] = charsrc[cnt];
			cnt++;
		}
	return (dst);
}
