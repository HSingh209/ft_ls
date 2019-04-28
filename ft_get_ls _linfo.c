#include "ft_ls_hd.h"

static char		*ft_parse_old(char	*dir_time)
{
	char 	*result;
	int		i;

	i = -1;
	result = (char *)malloc(11);
	while (i++ < 6)
		*(result + i) = *(dir_time + (4 + i));
	while (i < 11)
	{
		*(result + i) = *(dir_time + (13 + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}

static char		*ft_parse_recent(char	*dir_time)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(12);
	while (i++ < 11)
		*(ret + i) = *(dir_time + (4 + i));
	*(ret + i) = '\0';
	return (ret);
}

char	*ft_parse_dtime(struct timespec m_time)
{
	static time_t 	now;
	char			*dir_time;

	now = time(NULL);
	dir_time = ctime(&m_time.tv_sec);
	printf("%s\n", dir_time);
	if (m_time.tv_sec + (SIXMONTHS) > now && m_time.tv_sec < now + SIXMONTHS)
	{
		printf("if check POST ft_parse_recent\n");
		return (ft_parse_recent(dir_time));
			printf("if check POST ft_parse_recent\n");
	}
	else
	{
		printf("if check PRE ft_parse_old\n");
		return (ft_parse_old(dir_time));
	//	printf("if check POST ft_parse_recent\n");
	}
}

void	ft_print_long(t_dir_info *dir)
{
	char	*dir_time_stamp;
printf("pre parse dtime\n");
	dir_time_stamp = ft_parse_dtime(dir->m_time);
	printf("prost parse dtime\n");
	printf("%s %d %s %s %lld %s %s\n", dir->permissions, dir->links, dir->owner,
							dir->group, dir->size, dir_time_stamp, dir->name);
	ft_strdel(&dir_time_stamp);
}