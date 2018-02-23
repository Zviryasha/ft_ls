/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:51:29 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:34:09 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		flags(int ac, char **ar, struct s_flags *t_fla)
{
	if (ac > 0)
	{
		if (is_flag(ar, 'l'))
			t_fla->l = 1;
		if (is_flag(ar, 't'))
			t_fla->t = 1;
		if (is_flag(ar, 'R'))
			t_fla->rr = 1;
		if (is_flag(ar, 'a'))
			t_fla->a = 1;
		if (is_flag(ar, 'r') == 1)
			t_fla->r = 1;
	}
	return (0);
}

int		is_flag(char **ar, char c)
{
	int i;
	int j;

	i = 1;
	while (ar[i] != NULL)
	{
		j = 0;
		while (ar[i][j] != '\0')
		{
			if (ar[i][0] == '-' && ar[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
