/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:33:20 by anorman           #+#    #+#             */
/*   Updated: 2019/06/25 16:56:40 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	st_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (8);
	if (c == '\n' || c == '\r' || c == '\f')
		return (3);
	return (0);
}

int			ft_atoi(const char *str)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	if (!str)
		return (0);
	while (st_isblank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + neg * (*str - 48);
		str++;
	}
	return (res);
}

/*
** ft_atoi sets all over/underflows as +-1
** for easy identification.
*/
