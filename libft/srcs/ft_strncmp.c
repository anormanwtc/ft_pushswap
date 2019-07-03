/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:42:09 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:59:26 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;
	int		exit;

	cnt = 0;
	exit = 0;
	if (s1 == s2)
		return (0);
	if (!s1)
		return (*s2 * -1);
	if (!s2)
		return (*s1);
	while ((unsigned char)s1[cnt] != '\0' && cnt < n && exit == 0)
	{
		if ((unsigned char)s1[cnt] == (unsigned char)s2[cnt])
			cnt++;
		else
			exit = 1;
	}
	if (cnt == n)
		return (0);
	return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
}
