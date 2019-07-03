/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:26:11 by anorman           #+#    #+#             */
/*   Updated: 2019/05/31 10:44:34 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_wdcnt(const char *str, char delim)
{
	int		cnt;
	int		wd;

	cnt = 0;
	wd = 0;
	while (str[cnt])
	{
		while (str[cnt] == delim && str[cnt])
			cnt++;
		if (str[cnt])
			wd++;
		while (str[cnt] != delim && str[cnt])
			cnt++;
	}
	return (wd);
}

char		**ft_strsplit(char const *s, char c)
{
	int		cnt;
	int		startend[2];
	int		wdcnt;
	char	**arr;

	if (!s)
		return (NULL);
	wdcnt = st_wdcnt(s, c);
	if (!(arr = (char **)malloc((wdcnt + 1) * sizeof(char *))))
		return (NULL);
	arr[wdcnt] = NULL;
	cnt = 0;
	wdcnt = 0;
	while (s[cnt])
	{
		while (s[cnt] == c && s[cnt])
			cnt++;
		startend[0] = cnt;
		while (s[cnt] != c && s[cnt])
			cnt++;
		startend[1] = cnt;
		if (startend[0] != startend[1])
			arr[wdcnt++] = ft_strsub(s, startend[0], startend[1] - startend[0]);
	}
	return (arr);
}
