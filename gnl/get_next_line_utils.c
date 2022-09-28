/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:20:26 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/28 23:40:02 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strchr(const char *s, int c)
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

char	*ft_strchop(char *str)
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
	result = (char *)malloc(sizeof(char) * (idx + 1));
	if (!result)
		return (NULL);
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

char	*ft_strjoin(char *str, char *buff)
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
