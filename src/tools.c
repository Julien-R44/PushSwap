/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:26:04 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/10 03:26:18 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_lower(int n, int n2)
{
	if (n < n2)
		return (1);
	return (0);
}

int		is_upper(int n, int n2)
{
	if (n > n2)
		return (1);
	return (0);
}

int		stack_is_sort(t_dlist *list, int (*cmp)(int, int))
{
	t_dlist *nav;

	nav = list;
	while (nav->next)
	{
		if (cmp(NODE_VALUE, NEXT_NODE_VALUE) == 0)
			return (0);
		nav = nav->next;
	}
	return (1);
}
