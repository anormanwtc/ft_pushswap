/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:42:09 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 16:25:01 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	cnt;
	int		exit;

	exit = 0;
	cnt = 0;
	if (s1 && !s2)
		return (*s1);
	if (!s1 && s2)
		return (*s2 * -1);
	if (!s1 && !s2)
		return (0);
	while ((unsigned char)s1[cnt] != '\0' && exit == 0)
	{
		if ((unsigned char)s1[cnt] == (unsigned char)s2[cnt])
			cnt++;
		else
			exit = 1;
	}
	return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
}
