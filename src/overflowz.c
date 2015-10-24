/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflowz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 02:39:07 by y0ja              #+#    #+#             */
/*   Updated: 2015/05/08 02:41:31 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	overflow_scan(int plen, int mlen, char *max, char *arg, int i)
{
	if (plen > mlen)
		return (TRUE);
	else if (plen == mlen)
	{
		while (arg[i])
		{
			if (arg[i] < max[i])
				return (FALSE);
			if (arg[i] > max[i])
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

t_bool			overflow_spotted(char *arg)
{
	int		i;
	int		mlen;
	char	*max;

	i = 0;
	while (arg[i] == '0')
		i++;
	if (arg[0] == '-')
	{
		max = ft_itoa(INT_MIN);
		mlen = ft_strlen(max);
	}
	else
	{
		max = ft_itoa(INT_MAX);
		mlen = ft_strlen(max);
	}
	return (overflow_scan(ft_strlen(&arg[i]), mlen, max, arg, i));
}
