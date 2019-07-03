/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:42:03 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:58:30 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	cnt1;
	size_t	cnt2;

	cnt1 = 0;
	cnt2 = 0;
	if (!s1 || !s2)
		return (s1);
	while (s1[cnt1])
		cnt1++;
	while (cnt2 < n && s2[cnt2])
	{
		s1[cnt1] = s2[cnt2];
		cnt1++;
		cnt2++;
	}
	s1[cnt1] = '\0';
	return (s1);
}
