/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:32:40 by anorman           #+#    #+#             */
/*   Updated: 2019/07/26 16:53:38 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# define BUFF 10

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
void			ft_calcrot(int *i, int *k, t_stk **stack);
void			ft_rota_to(t_stk **stack, int index);
void			ft_rotb_to(t_stk **stack, int index);
void			ft_rotr_num(t_stk **stack, int num, char type);
int				ft_shortest_to_pb(t_stk **stack);
int				ft_pushplace_a(int *arr, int len, int elem);
int				ft_pushplace_b(int *arr, int len, int elem);
void			ft_pbindex_inorder(t_stk **stack, int *index);

void			ft_stkdel(t_stk **stack);
t_stk			**ft_stknew(int len);
void			ft_stkprint(t_stk **stack);
void			ft_stksort(t_stk **stack);
void			ft_bigsort(t_stk **stack);

#endif
