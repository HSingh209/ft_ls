#include "ft_ls_hd.h"
/*
static void		ft_set_link(char *path, char **link, size_t size)
{
	char	*linkname;
	char	*tmp;

	linkname = malloc(size);
	readlink((const char *)path, linkname, size);
	linkname[size] = '\0';
	tmp = ft_strjoin(*link, " -> ");
	ft_strdel(link);
	ft_strdel(&tmp);
	*link = linkname;
}*/
/*
static char	ft_getdescriptor(mode_t m)
{
	if ((m & S_IFMT) == S_IFREG)
		return ('-');
	else if ((m & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((m & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((m & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((m & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((m & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((m & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('0');
}*/
/*
static char		*ft_parse_persmiss(mode_t st_mode)
{
	char *permissions;

	permissions = malloc(11);
	*(permissions + 0) = ft_getdescriptor(st_mode);
	*(permissions + 1) = (st_mode & S_IRUSR) ? 'r' : '-';
	*(permissions + 2) = (st_mode & S_IWUSR) ? 'w' : '-';
	*(permissions + 3) = (st_mode & S_IXUSR) ? 'x' : '-';
	*(permissions + 4) = (st_mode & S_IRGRP) ? 'r' : '-';
	*(permissions + 5) = (st_mode & S_IWGRP) ? 'w' : '-';
	*(permissions + 6) = (st_mode & S_IXGRP) ? 'x' : '-';
	*(permissions + 7) = (st_mode & S_IROTH) ? 'r' : '-';
	*(permissions + 8) = (st_mode & S_IWOTH) ? 'w' : '-';
	*(permissions + 9) = (st_mode & S_IXOTH) ? 'x' : '-';
	*(permissions + 10) = '\0';
	return (permissions);
}*/
