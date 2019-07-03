/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:11:05 by anorman           #+#    #+#             */
/*   Updated: 2019/07/03 17:11:45 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memtoa(void *p)
{
	char *str;
	char *temp;

	str = ft_uitoa_base((unsigned long long)(p), 16);
	temp = ft_strjoin("0x", str);
	free (str);
	str = temp;
	return (str);
}
