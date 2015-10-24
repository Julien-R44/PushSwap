/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:33:32 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/08 02:42:11 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include "libft.h"

#define NO_FLAG 0
#define I_FLAG 1
#define V_FLAG 2

#define NODE_VALUE ((t_val *)nav->content)->nb
#define NEXT_NODE_VALUE ((t_val *)nav->next->content)->nb

typedef unsigned int uiFlags;

typedef enum	e_err
{
	NO_ARGS,
	DOUBLON,
	NOT_A_NB,
	SYSCALL,
	OVERFLOW,
}				t_err;

typedef struct	s_all
{
	int			operations;
	t_dlist		*a;
	t_dlist		*b;
	uiFlags		opt;
}				t_all;

typedef struct	s_val
{
	int			nb;
}				t_val;

// overflooowz.c
t_bool		overflow_spotted(char *arg);

// main.c
void		interactiv_mode(t_all *all);
int			is_lower(int n, int n2);
int			is_upper(int n, int n2);

// parser.c
void		init_all(int ac, char **av, t_all *all);

// hooks.c
void		hooks(t_all *all, char *str);

// select_sort.c
int			find_max_val(t_dlist *list, int *vx);
void		rot2max_val(t_all *all, int max, int vx);
void		refill_stack_a(t_all *all);
void		selection_sort(t_all *all);

// operand.c
void		swap(t_dlist *list, int *op);
void		swap_2(t_all *all, int *op);
void		push(t_dlist **dst, t_dlist **src, int *op);
void		rotate(t_dlist **list, int *op);
void		rotate_2(t_all *all, int *op);

// operand2.c
void		rrotate(t_dlist **list, int *op);
void		rrotate_2(t_all *all, int *op);

// tools.c
int			is_lower(int n, int n2);
int			is_upper(int n, int n2);
int			stack_is_sort(t_dlist *list, int (*cmp)(int, int));

// misc.c
void		ft_error(int er);
void		display_stacks(t_all *all);

#endif
