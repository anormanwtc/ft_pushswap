/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:09:04 by anorman           #+#    #+#             */
/*   Updated: 2019/07/04 16:20:53 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_can_atoi(char *str)
{
	char	*intmax;
	int		big;
	int		i;

	i = 0;
	big = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		intmax = "2147483648";
	if (str[i] == '-' || str[i] == '+')
		i++;
	else
		intmax = "2147483647";
	while (str[i] > 47 && str[i] < 58 && *intmax)
		if (str[i++] > *intmax)
			big = 1;
	if (*intmax)
		return (1 + ft_isspace(str[0]) + !ft_isdigit(str[i]) * 2);
	else if (big)
		return (0);
	else if (str[i] > 47 && str[i] < 58)
		return (0);
	return (-1);
}

/*
** returns 1-4 if it fits, 1 is perfectly number, 2 is spaces before
** 3 is non numbers after, 4 is spaces and non numbers
** returns 0 if it wont fit in an integer.
** it should not get to the return -1
*/
