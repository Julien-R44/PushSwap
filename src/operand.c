/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 02:00:07 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/10 04:32:51 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap les deux premiers elements au sommet dune pile.
	ne fais rien si il y en a quun ou si la liste est vide
*/
void		swap(t_dlist *list, int *op)
{
	if (!list || !list->next)
		return ;
	ft_swap_contents(&list, &list->next);
	*op += 1;
}

void		swap_2(t_all *all, int *op)
{
	swap(all->a, op);
	swap(all->b, op);
}

/*
	Prend le premiere element au sommet d'une liste et la met
	sur l autre;
	ne fais rien si liste est vide
*/
void		push(t_dlist **dst, t_dlist **src, int *op)
{
	char	*str;

	if (*src == NULL)
		return ;
	str = ft_strdup((char *)(*src)->content);
	ft_dlstadd(dst, ft_dlstnew(str, ft_strlen(str)));
	ft_dlstdelone(src, NULL);
	*op += 1;
}

/*
	Decale d'une position tous les elements de la pile.
	(vers le haut, le premier element devient le dernier)
*/
void		rotate(t_dlist **list, int *op)
{
	t_dlist *nav;

	if (!(*list))
		return ;
	nav = *list;
	while (nav->next)
	{
		ft_swap_contents(&nav, &nav->next);
		nav = nav->next;
	}
	*op += 1;
}

void		rotate_2(t_all *all, int *op)
{
	rotate(&all->a, op);
	rotate(&all->b, op);
}
