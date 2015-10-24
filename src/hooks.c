/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 23:41:56 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/09 03:55:17 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_hook(t_all *all, char *str)
{
	if (ft_strequ(str, "sa"))
		swap(all->a, &all->operations);
	if (ft_strequ(str, "sb"))
		swap(all->b, &all->operations);
	if (ft_strequ(str, "ss"))
		swap_2(all, &all->operations);
}

static void	push_hook(t_all *all, char *str)
{
	if (ft_strequ(str, "pa"))
		push(&all->a, &all->b, &all->operations);
	if (ft_strequ(str, "pb"))
		push(&all->b, &all->a, &all->operations);
}

static void	rotate_hook(t_all *all, char *str)
{
	if (ft_strequ(str, "ra"))
		rotate(&all->a, &all->operations);
	if (ft_strequ(str, "rb"))
		rotate(&all->b, &all->operations);
	if (ft_strequ(str, "rr"))
		rotate_2(all, &all->operations);
}

static void	rrotate_hook(t_all *all, char *str)
{
	if (ft_strequ(str, "rra"))
		rrotate(&all->a, &all->operations);
	if (ft_strequ(str, "rrb"))
		rrotate(&all->b, &all->operations);
	if (ft_strequ(str, "rrr"))
		rrotate_2(all, &all->operations);
}

void		hooks(t_all *all, char *str)
{
	swap_hook(all, str);
	push_hook(all, str);
	rotate_hook(all, str);
	rrotate_hook(all, str);
}
