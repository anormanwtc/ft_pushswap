/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:02:14 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:15:59 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*chars;

	cnt = 0;
	chars = (unsigned char *)s;
	if (s)
		while (cnt < n)
		{
			if (chars[cnt] == (unsigned char)c)
				return ((void *)&chars[cnt]);
			cnt++;
		}
	return (NULL);
}
