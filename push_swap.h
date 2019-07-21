/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:32:40 by anorman           #+#    #+#             */
/*   Updated: 2019/07/21 14:27:38 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/includes/libft.h"

#define BUFF 20

typedef struct	s_stk
{
	int		*full;
	int		*start;
	int		len;
}				t_stk;

int				ft_stackfill(int ac, char **av, t_stk **list);
void			ft_do_inputs(t_stk **stacks);
int				ft_stackcheck(t_stk **stack);
int				ft_no_dups(t_stk *stack);

int				ft_stkswap(char ver, t_stk **stacks);
int				ft_stkrotate(char ver, t_stk **stacks);
int				ft_stkrevtate(char ver, t_stk **stacks);
int				ft_stkpush(char ver, t_stk **stacks);

int				ft_stackmin(t_stk *stack);
int				ft_stackmax(t_stk *stack);

void			ft_stkdel(t_stk **stack);
t_stk			**ft_stknew(int len);
void			ft_stkprint(t_stk **stack);

#endif
