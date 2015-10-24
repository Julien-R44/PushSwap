/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 23:42:42 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/08 02:44:02 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int er)
{
	if (er == NOT_A_NB)
		ft_putendl("Error : a param is not a number");
	if (er == DOUBLON)
		ft_putendl("Error : doublon arn't allowed");
	if (er == OVERFLOW)
		ft_putendl("Error : Overflow");
	if (er == NO_ARGS)
	{
		ft_putendl("utilisation : ./push_swap [-iv] [numbers to sort..]");
		ft_putendl("-i for interactive mode, -v to show stack for each action.");
	}
	exit(-1);
}

void	ft_printdlist2(t_dlist *list)
{
	t_dlist *nav;
	t_val *val;

	nav = ft_dlstlast(list);
	while (nav)
	{
		val = nav->content;
		ft_putnbr(val->nb);
		ft_putchar(' ');
		nav = nav->before;
	}
}

void	display_stacks(t_all *all)
{
	ft_putstr("a : ");
	ft_printdlist2(all->a);
	ft_putchar('\n');
	ft_putstr("b : ");
	ft_printdlist2(all->b);
	ft_putchar('\n');
}
