/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:16:07 by anorman           #+#    #+#             */
/*   Updated: 2019/05/31 16:09:47 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	cnt;
	size_t	s_e[2];

	cnt = 0;
	if (!s)
		return (NULL);
	while (st_isblank(s[cnt]) && s[cnt])
		cnt++;
	s_e[0] = cnt;
	while (s[cnt])
		cnt++;
	while (st_isblank(s[cnt - 1]) && cnt > s_e[0])
		cnt--;
	s_e[1] = cnt - 1;
	if (!(trim = (char *)malloc((s_e[1] - s_e[0] + 2) * sizeof(char))))
		return (NULL);
	cnt = 0;
	while (s_e[0] + cnt < s_e[1] + 1)
	{
		trim[cnt] = s[s_e[0] + cnt];
		cnt++;
	}
	trim[cnt] = '\0';
	return (trim);
}
