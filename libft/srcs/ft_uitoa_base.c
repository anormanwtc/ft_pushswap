/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:06:12 by anorman           #+#    #+#             */
/*   Updated: 2019/07/03 16:17:15 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	st_intlen(unsigned long long n, size_t base)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res++;
		n = n * -1;
	}
	while ((n = n / (unsigned long long)base) > 0)
		res++;
	return (res);
}

char		*ft_uitoa_base(unsigned long long n, size_t base)
{
	char	*ans;
	int		cnt;
	int		neg;

	cnt = st_intlen(n, base);
	neg = 1;
	if (!base || base > 36 || !(ans = (char *)malloc((cnt + 1) * sizeof(char))))
		return (NULL);
	ans[cnt--] = '\0';
	if (n < 0)
	{
		ans[0] = '-';
		neg = -1;
	}
	while (cnt > -1 && ans[cnt] != '-')
	{
		if ((n % (unsigned long long)base) * neg < 10)
			ans[cnt--] = ((n % (unsigned long long)base) * neg) + '0';
		else
			ans[cnt--] = ((n % (unsigned long long)base) * neg) - 10 + 'a';
		n = (n / (unsigned long long)base);
	}
	return (ans);
}

/*
** ((n % 10) * neg) + '0' works despite google disagreeing with the maths
** that is google thinks -4 % 10 == 6 but its -4 % 10 == -4 here.
**
** An itoa_base that can work with any negative base :D
** I cut off the max base at 36 (ie 10 + all letters)
*/
