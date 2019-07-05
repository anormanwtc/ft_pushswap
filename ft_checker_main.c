/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:14:54 by anorman           #+#    #+#             */
/*   Updated: 2019/07/05 11:15:04 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		st_do_inputs(t_stk **stacks)
{
	char	*str;
	char	*temp;
	int		red;
	int		i;

	str = (char *)malloc(BUFF + 1);
	while ((red = read(1, str, BUFF)) > 0)
	{
		str[red] = '\0';
		i = 0;
		while (str[i] != 's' && str[i] != 'p' && str[i] != 'r')
			i++;
		if (str[i++] == 's')
			st_swap(str[i++], stacks);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_stk	*list;

	list = NULL;
	if (ac < 2)
		return (0);
	av++;
	if (!(list = ft_stacksfill(ac, av, list)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_stackprint(list);
	return (0);
