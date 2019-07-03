/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:19:10 by anorman           #+#    #+#             */
/*   Updated: 2019/05/23 13:22:09 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (8);
	return (0);
}

/*
** I tested og isprint from 0 to 178 and these are the values it is true for
** 31 < c < 127 (not inclusive)
*/
