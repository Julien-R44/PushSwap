/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 00:38:25 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/08 03:47:51 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rrotate(t_dlist **list, int *op)
{
	t_dlist *nav;

	nav = ft_dlstlast(*list);
	if (!nav)
		return ;
	while (nav->before)
	{
		ft_swap_contents(&nav, &nav->before);
		nav = nav->before;
	}
	*op += 1;
}

void		rrotate_2(t_all *all, int *op)
{
	rrotate(&all->a, op);
	rrotate(&all->b, op);
}
