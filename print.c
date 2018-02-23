/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:51:33 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:51:45 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_struct(t_dir *ddir)
{
	t_dir	*tmp;
	int		len_nlink;
	int		len_u_name;
	int		len_g_name;
	int		len_size;

	tmp = ddir;

	len_nlink = 0;
	len_u_name = 0;
	while (ddir != NULL)
	{
		if (len_nlink < (int)ft_strlen(ft_itoa(ddir->nlink)))
			len_nlink = ft_strlen(ft_itoa(ddir->nlink));
		if (len_u_name < (int)ft_strlen(ddir->u_name))
			len_u_name = ft_strlen(ddir->u_name);
		if (len_g_name < (int)ft_strlen(ddir->u_name))
			len_g_name = ft_strlen(ddir->u_name);
		if (len_size < (int)ft_strlen(ft_itoa(ddir->size)))
			len_size = ft_strlen(ft_itoa(ddir->size));
		ddir = ddir->next;
	}
	while (tmp != NULL)
	{
		printf("%s ",tmp->rwx);
		printf("%*d ", len_nlink, tmp->nlink);
		printf("%-*s", len_u_name, tmp->u_name);
		printf("%-*s", len_g_name, tmp->g_name);
		printf("%*d ", len_size, tmp->size);
		printf("%s\n", tmp->time);
		tmp = tmp->next;
	}
}