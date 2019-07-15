/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:32:40 by anorman           #+#    #+#             */
/*   Updated: 2019/07/15 16:39:18 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPUSHSWAP_H
# define LIBFTPUSHSWAP_H

#include "libft/includes/libft.h"

#define BUFF 20

typedef struct	s_stk
{
	int		*full;
	int		*start;
	int		len;
}				t_stk;

//long			ft_sort_takeout(int len);

void			ft_do_inputs(t_stk **stacks);
//int				ft_stackcheck(int **stack);

int				ft_stkswap(char ver, t_stk **stacks);
//int				ft_stkrotate(char ver, t_stk **stacks);
int				ft_stkpush(char ver, t_stk **stacks);

void			ft_stkdel(t_stk *stack);
t_stk			*ft_stknew(int len);

#endif
