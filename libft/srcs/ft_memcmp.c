/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:23:43 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:27:38 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*uchars1;
	unsigned char	*uchars2;

	cnt = 0;
	uchars1 = (unsigned char *)s1;
	uchars2 = (unsigned char *)s2;
	if (!s1 && s2)
		return (*uchars2 * -1);
	if (s1 && !s2)
		return (*uchars1);
	if (!s1 && !s2)
		return (0);
	while (cnt < n && uchars1[cnt] == uchars2[cnt])
	{
		cnt++;
	}
	if (cnt == n)
		return (0);
	return (uchars1[cnt] - uchars2[cnt]);
}
