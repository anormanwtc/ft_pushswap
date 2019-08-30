/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_av_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:31:30 by anorman           #+#    #+#             */
/*   Updated: 2019/08/30 10:11:59 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_av_split(char *av, int *ac)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = ft_strsplit(av, ' ')))
	{
		*ac = 0;
		return (NULL);
	}
	while (ret[i])
		i++;
	*ac = i;
	return (ret);
}

void	ft_av_del(char **av)
{
	while (*av)
	{
		free(*av);
		av++;
	}
}
