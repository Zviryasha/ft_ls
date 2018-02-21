#include "stdio.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "libft/libft.h"

int main(void)
{
	DIR *p_dir;
	struct dirent *dir;
	int a;
	struct stat buf;
	int i;
	struct passwd *pass;
	struct group *group;


	i =0;
	p_dir = opendir(".");
	if (p_dir == NULL)
	{
		printf("Can't open dir!\n");
		return(0);
	}
	while ((dir = readdir(p_dir)) != NULL)
	{
		if ((a = stat(dir->d_name, &buf)) <  0)
		{
			printf("stat == 0\n");
			return (0);
		}
	printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
    printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf.st_mode & S_IROTH) ? "r" : "-");
    printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
    printf("%4d",buf.st_nlink);
	pass = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	printf(" %s", pass->pw_name);
	printf("  %s", group->gr_name);
	printf("%10lld",  buf.st_size);
	char *s;
	s = ft_strnew(50);
	int j;
	j = 0;
	char *t;
	t = ft_strnew(50);
	ft_strncpy(s, ctime(&buf.st_mtime), 16);
	while (j != (int)ft_strlen(s) + 4)
	{
		t[j] = s[j + 4];
		j++;
	}
	free(s);
	printf("  %s", t);
	printf("  %s\n", dir->d_name);
	free(t);
		i++;
	}
	closedir(p_dir);
}