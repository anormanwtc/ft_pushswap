/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:53:41 by anorman           #+#    #+#             */
/*   Updated: 2019/06/25 16:48:05 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrev(char *ans)
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
