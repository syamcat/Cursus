/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:18:15 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/27 20:38:10 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

static char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx <= len)
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	return (NULL);
}

static char	*ft_strndup(const char *s1, int n)
{
	int		idx;
	int		len_s1;
	char	*result;

	idx = 0;
	len_s1 = n;
	result = (char *)malloc(sizeof(const char) * len_s1 + 1);
	if (!result)
		return (NULL);
	while (idx < len_s1)
	{
		result[idx] = s1[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

static char	*ft_strchop(char *str, char *store)
{
	char	*result;
	int		idx;

	idx = 0;
	if (!str)
		return (NULL);
	while (str[idx] != '\n' && str[idx])
		idx++;
	if (str[idx] == '\n')
		idx++;
	result = ft_strndup(str, idx);
	store = ft_strjoin(store, &str[idx]);
	return (result);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	idx;

	if (!(s1 && s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	idx = -1;
	if (!result)
		return (0);
	while (++idx < len_s1)
		result[idx] = s1[idx];
	idx = -1;
	while (++idx < len_s2)
		result[len_s1 + idx] = s2[idx];
	result[len_s1 + idx] = '\0';
	free(s2);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*store;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE];
	char		*result;

	store = ft_strndup("", 0);
	result = NULL;
	while (0 < (rd_size = read(fd, buff, BUFFER_SIZE - 2)))
	{
		buff[BUFFER_SIZE - 1] = '\0';
		if (!ft_strchr(buff, '\n'))
		{
			store = ft_strjoin(store, ft_strndup(buff, BUFFER_SIZE));
			continue ;
		}
		else
		{
			result = ft_strjoin(store, ft_strchop(buff, store));
			break ;
		}
	}
	if (rd_size < 0)
		return (NULL);
	return (result);
}
