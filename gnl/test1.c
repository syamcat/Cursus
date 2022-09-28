/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:18:15 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/28 22:04:42 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	idx;

	if (!s)
		return (0);
	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

void	ft_bnull(void *s, size_t n)
{
	unsigned char	*result;
	size_t			idx;

	idx = 0;
	if (n == 0)
		return ;
	else
	{
		result = (unsigned char *)s;
		while (idx < n)
		{
			result[idx] = '\0';
			idx++;
		}
	}
	return ;
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

// static char	*ft_strndup(char *s1, int n)
// {
// 	int		idx;
// 	int		len_s1;
// 	char	*result;

// 	idx = 0;
// 	len_s1 = n;
// 	result = (char *)malloc(sizeof(char) * len_s1 + 1);
// 	if (!result)
// 		return (NULL);
// 	while (idx < len_s1)
// 	{
// 		result[idx] = s1[idx];
// 		idx++;
// 	}
// 	result[idx] = '\0';
// 	return (result);
// }

static char	*ft_strchop(char *str)
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
	result = malloc(idx + 1);
	idx = 0;
	while (str[idx] != '\n' && str[idx])
	{
		result[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
		result[idx++] = '\n';
	result[idx] = '\0';
	return (result);
}

// static char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*result;
// 	size_t	len_s1;
// 	size_t	len_s2;
// 	size_t	idx;

// 	if (!s1)
// 		s1 = malloc(1);
// 	s1[0] = '\0';
// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	result = (char *)malloc(len_s1 + len_s2 + 1);
// 	idx = -1;
// 	if (!result)
// 		return (0);
// 	while (++idx < len_s1)
// 		result[idx] = s1[idx];
// 	idx = -1;
// 	while (++idx < len_s2)
// 		result[len_s1 + idx] = s2[idx];
// 	result[len_s1 + idx] = '\0';
// 	free(s1);
// 	return (result);
// }

static char	*ft_strjoin(char *str, char *buff)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (!ret)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	j = 0;
	while (buff[j])
		ret[i++] = buff[j++];
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	*new_str(char *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((s[i] != '\n') && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	ret = malloc(ft_strlen(s) - i + 1);
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	free(s);
	return (ret);
}

// void	ft_get_line(int fd, char *buff,ssize_t rd_size, char *store, char *result)
// {
// 	while (1)
// 	{
// 		rd_size = read(fd, buff, BUFFER_SIZE);
// 		if (0 <= rd_size)
// 		{
// 			buff[BUFFER_SIZE] = '\0';
// 			if (ft_strchr(buff, '\n') || rd_size < BUFFER_SIZE)
// 			{
// 				store = ft_strjoin(store, buff);
// 				ft_bnull(buff, ft_strlen(buff));
// 				break ;
// 			}
// 			else
// 			{
// 				store = ft_strjoin(store, buff);
// 				ft_bnull(buff, ft_strlen(buff));
// 				continue ;
// 			}
// 		}
// 		else
// 		{
// 			result = NULL;
// 			return ;
// 		}
// 	}
// }

char	*get_next_line(int fd)
{
	static char	*store;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	// ft_bnull(buff, ft_strlen(buff));
	// rd_size = 0;
	// store = malloc(1);
	// if (!store)
	// 	return (NULL);
	// store[0] = '\0';
	// ft_get_line(fd, buff, rd_size, store, result);
	while (1)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (0 <= rd_size)
		{
			buff[BUFFER_SIZE] = '\0';
			if (ft_strchr(buff, '\n') || rd_size == 0)
			{
				store = ft_strjoin(store, buff);
				ft_bnull(buff, ft_strlen(buff));
				break ;
			}
			else
			{
				store = ft_strjoin(store, buff);
				ft_bnull(buff, ft_strlen(buff));
				continue ;
			}
		}
		else
			break;
	}
	result = ft_strchop(store);
	store = new_str(store);
	// if (rd_size < 0)
	// 	return (NULL);
	return (result);
}
