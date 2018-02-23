/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rwx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:26:32 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/23 14:32:21 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	rwx(struct stat buf, t_dir *ddir)
{
	ddir->rwx = ft_strnew(10);
	ft_memset(ddir->rwx, '-', 10);
	if (S_ISDIR(buf.st_mode) == 1)
		ddir->rwx[0] = 'd';
	if (buf.st_mode & S_IRUSR)
		ddir->rwx[1] = 'r';
	if (buf.st_mode & S_IWUSR)
		ddir->rwx[2] = 'w';
	if (buf.st_mode & S_IXUSR)
		ddir->rwx[3] = 'x';
	if (buf.st_mode & S_IRGRP)
		ddir->rwx[4] = 'r';
	if (buf.st_mode & S_IWGRP)
		ddir->rwx[5] = 'w';
	if (buf.st_mode & S_IXGRP)
		ddir->rwx[6] = 'x';
	if (buf.st_mode & S_IROTH)
		ddir->rwx[7] = 'r';
	if (buf.st_mode & S_IWOTH)
		ddir->rwx[8] = 'w';
	if (buf.st_mode & S_IXOTH)
		ddir->rwx[9] = 'x';
}
