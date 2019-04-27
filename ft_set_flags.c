#include "ft_ls_hd.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static	t_bool 	ft_valid_flag(const char *args)
{
	int i;

		printf("test_ft_valid_flag__\n");

	i = 0;
	if (args[i] != '-')
		return (false);
	i++;
	while (args[i])
	{
		if (args[i] == 'R' || args[i] == 'a' || args[i] == 't' || 
			args[i] == 'r' || args[i] == 'l')
			i++;
		else
		{
			printf("ft_ls: illegal option -- %c\n", args[i]);
			printf("usage: ft_ls [-Ralrt] [file ...]");
			return (false);
		}
	}
	return (true);
}

static t_node	*ft_new_flg(void)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->l_spec = 0;
	new->recur = 0;
	new->time = 0;
	new->rever = 0;
	new->all = false;
	return (new);
}

t_node	*ft_ls_flags(const char **av)
{
	size_t i;
	t_node *flags;

	flags = ft_new_flg(); //same as calling "ft_newflags()" for flags
	
	i = 1;
	while (av[i] && *(*(av + i) + 0) == '-')//This loop is to get all flags only
	{
	//	printf("test_ft_lsflag__\n");
		if (ft_valid_flag(av[i]))
		{
			flags->rever = (ft_strchr(av[i], 'r') ? 1 : 0);
			flags->time = (ft_strchr(av[i], 't') ? 1 : 0);
			flags->recur = ft_strchr(av[i], 'R') ? 1 : 0;
			flags->all = ft_strchr(av[i], 'a') ? true : false;
			flags->l_spec = ft_strchr(av[i], 'l') ? 1 : 0;
			i++;
		}
		else
			exit(1);
	}
	return (flags);
}