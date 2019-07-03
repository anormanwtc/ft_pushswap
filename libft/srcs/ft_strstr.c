/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:37:30 by anorman           #+#    #+#             */
/*   Updated: 2019/06/13 17:30:34 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		nee;
	int		hay;

	hay = 0;
	if (!(needle[0]) || needle == haystack)
		return ((char *)haystack);
	if (!haystack)
		return (NULL);
	while (haystack[hay] != '\0')
	{
		nee = 0;
		while (haystack[hay + nee] == needle[nee] && needle[nee])
			nee++;
		if (needle[nee] == '\0')
			return ((char *)&haystack[hay]);
		hay++;
	}
	return (NULL);
}
