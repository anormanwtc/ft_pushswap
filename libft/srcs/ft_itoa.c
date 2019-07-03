/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:09:42 by anorman           #+#    #+#             */
/*   Updated: 2019/06/18 16:48:00 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_intlen(int n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		res++;
		n = n * -1;
	}
	while ((n = n / 10) > 0)
		res++;
	return (res);
}

static void	st_strrev(char *ans)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = 0;
	while (ans[end + 1])
		end++;
	while (end > start)
	{
		temp = ans[end];
		ans[end] = ans[start];
		ans[start] = temp;
		end--;
		start++;
	}
}

char		*ft_itoa(int n)
{
	char	*ans;
	int		cnt;
	int		neg;

	cnt = 0;
	neg = 1;
	if (!(ans = (char *)malloc((st_intlen(n) + 1) * sizeof(char))))
		return (NULL);
	ans[st_intlen(n)] = '\0';
	if (n < 0)
	{
		ans[st_intlen(n) - 1] = '-';
		neg = -1;
	}
	while ((n / 10))
	{
		ans[cnt++] = ((n % 10) * neg) + '0';
		n = (n / 10);
	}
	ans[cnt] = ((n % 10) * neg) + '0';
	st_strrev(ans);
	return (ans);
}

/*
** ((n % 10) * neg) + '0' works despite google disagreeing with the maths
** that is google thinks -4 % 10 == 6 but its -4 % 10 == -4 here.
*/
