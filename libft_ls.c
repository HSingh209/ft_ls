#include "ft_ls_hd.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int 	ft_strlen(const char *s)
{
	int c;		//changed to int from size_t

	c = 0;
	while (s[c])
	{
		c++;
	}
	return (c);
}

char	*join_str(const char *s1, const char *s2, int len1, int len2)
{
	char	*join;
	int		i1;
	int		i2;

	if (!(join = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		join[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		join[i1] = s2[i2];
		i1++;
		i2++;
	}
	join[i1] = '\0';
	return (join);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen((char *)s1);
		s2_len = ft_strlen((char *)s2);
		return (join_str(s1, s2, s1_len, s2_len));
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}