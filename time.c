/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:17:39 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:30:41 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_time(struct stat buf, struct s_dir *ddir, struct dirent *dir)
{
	char	*s;
	int		j;

	s = ft_strnew(50);
	j = 0;
	ddir->time = ft_strnew(50);
	ft_strncpy(s, ctime(&buf.st_mtime), 16);
	while (j != (int)ft_strlen(s) + 4)
	{
		ddir->time[j] = s[j + 4];
		j++;
	}
	free(s);
	ddir->name = ft_strnew(ft_strlen(dir->d_name));
	ft_strcpy(ddir->name, dir->d_name);
}
