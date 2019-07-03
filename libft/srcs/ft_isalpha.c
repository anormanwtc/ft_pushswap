/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:34:00 by anorman           #+#    #+#             */
/*   Updated: 2019/05/23 16:13:02 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c > 64 && c < 91)
		return (8);
	if (c > 96 && c < 123)
		return (8);
	return (0);
}

/*
** returns nonzero if the value matches a decimal or octal
** alphabet character.
*/
