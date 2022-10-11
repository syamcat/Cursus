/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:24:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/10/11 18:58:39 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*new_str(char *s)
{
	char	*ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
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

char	*get_next_line(int fd)
{
	static char	*store;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	while (1)
	{
		ft_bnull(buff, ft_strlen(buff));
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (rd_size < 0)
		{
			store = NULL;
			break ;
		}
		buff[rd_size] = '\0';
		store = ft_strjoin(store, buff);
		if (ft_strchr(buff, '\n') || rd_size == 0)
			break ;
		else
			continue ;
	}
	result = ft_strchop(store);
	store = new_str(store);
	return (result);
}
