/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 02:06:08 by jripoute          #+#    #+#             */
/*   Updated: 2015/09/30 03:05:22 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	interactiv_mode_help(void)
{
	ft_putendl("Available commands :");
	ft_putendl("sa, sb, sa, pa, pb, ra, rb, rr, rra, rrb, rrr.\n");
}

void	interactiv_mode(t_all *all)
{
	char *str;

	interactiv_mode_help();
	while (get_next_line(1, &str) > 0)
	{
		hooks(all, str);
		display_stacks(all);
		ft_putchar('\n');
		free(str);
	}
}

void	go_back(t_all *all, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		rrotate(&all->a, &all->operations);
		ft_putstr("rra ");
		i++;
	}
}

void	specific_sort(t_all *all, t_dlist *nav)
{
	int i;
	int j;
	int len;

	j = 2;
	len = ft_dlstlen(nav);
	while (stack_is_sort(nav, is_upper) == 0)
	{
		i = len - j;
		while (i)
		{
			rotate(&nav, &all->operations);
			ft_putstr("ra ");
			swap(nav, &all->operations);
			ft_putstr("sa ");
			i--;
		}
		go_back(all, len - 3);
		j++;
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		ft_error(NO_ARGS);
	init_all(ac, av, &all);
	display_stacks(&all);
	if (all.opt & I_FLAG)
		interactiv_mode(&all);
	else
	{
		// if (stack_is_sort(all.a, is_lower))
			// specific_sort(&all, all.a);
		// else
			selection_sort(&all);


		printf("%d ops.\n", all.operations );
		display_stacks(&all);
	}
	return (0);
}
