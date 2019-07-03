/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:33:49 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:15:05 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*ucharsrc;
	unsigned char	*uchardst;

	cnt = 0;
	ucharsrc = (unsigned char *)src;
	uchardst = (unsigned char *)dst;
	if (!dst || !src)
		return (dst);
	while (cnt < n && ucharsrc[cnt] != (unsigned char)c)
	{
		uchardst[cnt] = ucharsrc[cnt];
		cnt++;
	}
	if (cnt < n && ucharsrc[cnt] == (unsigned char)c)
	{
		uchardst[cnt] = ucharsrc[cnt];
		cnt++;
		return (&dst[cnt]);
	}
	else
		return (NULL);
}
