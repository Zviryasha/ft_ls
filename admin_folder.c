/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin_folder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:36:35 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:29:21 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	am_pass(struct stat buf, struct s_dir *ddir)
{
	struct passwd	*pass;
	struct group	*group;

	ddir->nlink = buf.st_nlink;
	pass = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	ddir->u_name = ft_strnew(50);
	ft_strcpy(ddir->u_name, pass->pw_name);
	ddir->g_name = ft_strnew(50);
	ft_strcpy(ddir->g_name, group->gr_name);
	ddir->size = buf.st_size;
}
