/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 01:50:22 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/08 03:55:44 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_val(t_dlist *list, int *vx)
{
	t_dlist		*nav;
	int			max_val;
	int			i;

	i = 0;
	*vx = 0;
	max_val = INT_MIN;
	nav = list;
	while (nav)
	{
		if (NODE_VALUE > max_val)
		{
			max_val = NODE_VALUE;
			*vx = i;
		}
		nav = nav->next;
		i++;
	}
	return (max_val);
}

t_bool	stack_need2swap(t_dlist *nav)
{
	if (NEXT_NODE_VALUE > NODE_VALUE)
		return (TRUE);
	return (FALSE);
}

void	do_rot2max_val(t_all *all, int vx, char *str, void (*rot)(t_dlist**, int*))
{
	while (vx)
	{
		rot(&all->a, &all->operations);
		ft_putstr(str);
		vx--;
	}
}

void	rot2max_val(t_all *all, int max, int vx)
{
	if (vx > (ft_dlstlen(all->a) / 2))
		do_rot2max_val(all, -(vx - ft_dlstlen(all->a)), "rra ", rrotate);
	else
		do_rot2max_val(all, vx, "ra ", rotate);
}

void	refill_stack_a(t_all *all)
{
	while (all->b)
	{
		push(&all->a, &all->b, &all->operations);
		ft_putstr("pa ");
	}
	ft_putchar('\n');
}

void	selection_sort(t_all *all)
{
	int len;
	int	max;
	int	vx;

	len = ft_dlstlen(all->a);
	if (stack_is_sort(all->a, is_upper))
		return ;
	if (stack_need2swap(all->a) == TRUE)
	{
		swap(all->a, &all->operations);
		ft_putstr("sa ");
	}
	while (len - 1)
	{
		max = find_max_val(all->a, &vx);
		rot2max_val(all, max, vx);
		if (stack_is_sort(all->a, is_upper))
			break ;
		push(&all->b, &all->a, &all->operations);
		ft_putstr("pb ");
		len--;
	}
	refill_stack_a(all);
}
