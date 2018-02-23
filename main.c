/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:34:55 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:36:38 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **ar)
{
	t_dir			*ddir;
	struct s_flags	t_fla;

	ddir = NULL;
	flags(ac, ar, &t_fla);
	if (open_folder(&ddir) == -1)
		return (0);
	print_struct(ddir);
	free_struct(ddir);
}

int		open_folder(t_dir **ddir)
{
	DIR				*p_dir;
	struct dirent	*dir;

	p_dir = opendir(".");
	if (p_dir == NULL)
	{
		printf("Can't open dir!\n");
		return (-1);
	}
	while ((dir = readdir(p_dir)) != NULL)
		*ddir = new_item(dir, *ddir);
	closedir(p_dir);
	return (0);
}

t_dir	*new_item(struct dirent *dir, t_dir *ddir)
{
	struct stat	buf;
	t_dir		*tmp;

	tmp = malloc(sizeof(t_dir));
	if (tmp)
	{
		if (stat(dir->d_name, &buf) < 0)
		{
			printf("stat == 0\n");
			return (0);
		}
		rwx(buf, tmp);
		am_pass(buf, tmp);
		ls_time(buf, tmp, dir);
		tmp->next = ddir;
	}
	return (tmp);
}

void	free_struct(t_dir *ddir)
{
	t_dir *fr;

	while (ddir != NULL)
	{
		free(ddir->rwx);
		free(ddir->time);
		free(ddir->name);
		free(ddir->u_name);
		free(ddir->g_name);
		fr = ddir->next;
		free(ddir);
		ddir = fr;
	}
}
