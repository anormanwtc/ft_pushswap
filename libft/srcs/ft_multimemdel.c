/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multimemdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:38:24 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 13:40:03 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void		ft_multimemdel(int num, ...)
{
	int		i;
	void	**input;
	va_list	ap;

	i = 0;
	va_start(ap, num);
	while (i++ < num)
		ft_memdel(va_arg(ap, void **));
	va_end(ap);
}
