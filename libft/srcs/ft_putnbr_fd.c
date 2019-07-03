/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:31:01 by anorman           #+#    #+#             */
/*   Updated: 2019/06/18 16:56:11 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int		neg;

	neg = 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		neg = -1;
	}
	if ((nbr / 10) * neg > 0)
		ft_putnbr_fd((nbr / 10) * neg, fd);
	ft_putchar_fd(((nbr % 10) * neg) + '0', fd);
}

/*
** ((nbr % 10) * neg) + '0' works despite google disagreeing with the maths
** that is google thinks -4 % 10 == 6 but its -4 % 10 == -4 here.
*/
