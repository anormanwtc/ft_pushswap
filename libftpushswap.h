/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:32:40 by anorman           #+#    #+#             */
/*   Updated: 2019/07/08 16:07:59 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPUSHSWAP_H
# define LIBFTPUSHSWAP_H

#include "libft/includes/libft.h"

#define BUFF 20

typedef struct	s_stk
{
	int				val;
	struct s_stk	*next;
	struct s_stk	*prev;
}				t_stk;

t_stk			*ft_stackfill(int ac, char **av);
void			ft_do_inputs(t_stk **stacks);

t_stk			*ft_stackadd(t_stk *start, int val);
void			ft_stackrem(t_stk **node);
void			ft_stackdel(t_stk *node);
void			ft_stackprint(t_stk *start);

#endif
