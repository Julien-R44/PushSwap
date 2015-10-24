/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 23:39:06 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/08 02:50:07 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_it_a_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 &&
			!(str[i] == '-' && ft_isdigit(str[i+1])))
			return (0);
		i++;
	}
	return (1);
}

static int		check_doublons(t_dlist *list, char *str)
{
	t_dlist *nav;

	nav = list;
	while (nav)
	{
		if (ft_atoi(str) == NODE_VALUE)
			return (1);
		nav = nav->next;
	}
	return (0);
}

static t_dlist	*init_pile(int ac, char **av)
{
	int		i;
	t_dlist	*list;
	t_val	val;

	i = (av[1][0] == '-' && ft_isalpha(av[1][1])) ? 2 : 1;
	list = NULL;
	while (av[i])
	{
		if (!is_it_a_number(av[i]))
		{
			printf("[%s]", av[i]);
			ft_error(NOT_A_NB);
		}
		if (check_doublons(list, av[i]) == 1)
			ft_error(DOUBLON);
		if (overflow_spotted(av[i]) == TRUE)
			ft_error(OVERFLOW);
		val.nb = ft_atoi(av[i]);
		ft_dlstadd_end(&list, ft_dlstnew(&val, sizeof(t_val)));
		i++;
	}
	if (list == NULL)
		ft_error(NO_ARGS);
	return (list);
}

static void	get_opt_flags(int ac, char **av, uiFlags *opts)
{
	if (ft_strequ(av[1], "-i"))
		*opts |= I_FLAG;
	else if (ft_strequ(av[1], "-v"))
		*opts |= V_FLAG;
	else if (ft_strequ(av[1], "-iv") || ft_strequ(av[1], "-vi"))
		*opts = V_FLAG | I_FLAG;
}

void	init_all(int ac, char **av, t_all *all)
{
	all->a = NULL;
	all->b = NULL;
	all->opt = NO_FLAG;
	all->operations = 0;
	get_opt_flags(ac, av, &all->opt);
	all->a = init_pile(ac, av);
}
