/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:18:16 by anorman           #+#    #+#             */
/*   Updated: 2019/07/02 17:01:23 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char *str1, char *str2)
{
	char *res;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	res = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (res);
}
