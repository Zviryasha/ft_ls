/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:33:37 by opanchen          #+#    #+#             */
/*   Updated: 2018/02/22 14:34:42 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include "stdio.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include "libft/libft.h"

typedef struct s_dir	t_dir;

struct		s_dir
{
	char			*rwx;
	char			*time;
	char			*name;
	int				nlink;
	char			*u_name;
	char			*g_name;
	int				size;
	t_dir			*next;
};

struct		s_flags
{
	int				l;
	int				a;
	int				r;
	int				rr;
	int				t;
};

int			open_folder(t_dir **ddir);
int			is_flag(char **ar, char c);
int			flags(int ac, char **ar, struct s_flags *t_fla);
void		rwx(struct stat buf, t_dir *ddir);
void		ls_time(struct stat buf, struct	s_dir *ddir, struct dirent *dir);
void		am_pass(struct stat buf, struct	s_dir *ddir);
t_dir		*new_item(struct dirent *dir, t_dir *ddir);
void		free_struct(t_dir *ddir);
void		print_struct(t_dir *ddir);

#endif
