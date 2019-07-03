/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:37:30 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 17:43:39 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	h;
	size_t	nee;

	h = 0;
	if (!needle || !needle[0] || needle == hay)
		return ((char *)hay);
	if (!hay)
		return (NULL);
	while (*hay && h < len)
	{
		nee = 0;
		while (hay[h + nee] == needle[nee] && h + nee < len && needle[nee])
			nee++;
		if (needle[nee] == '\0' && h + nee < len)
			return ((char *)&hay[h]);
		h++;
	}
	return (NULL);
}
