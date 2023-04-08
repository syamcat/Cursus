/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:24:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/04/08 13:42:26 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*new_str(char *s, t_file **files)
{
	char	*ret;
	int		i;
	int		j;

	if (!s)
	{
		free((*files)->store);
		return (NULL);
	}
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
	ret = malloc(ft_strlen2(s, 1, 0) - i + 1);
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	free(s);
	return (ret);
}

static char	*ft_adstore(char *store, int fd)
{
	ssize_t		rd_size;
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ft_bnull(buff, BUFFER_SIZE + 1);
	while (1)
	{
		ft_bnull(buff, ft_strlen2(buff, 1, 0));
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
	}
	free(buff);
	return (store);
}

void	ft_lstadd_back(t_file **lst, t_file *new)
{
	t_file	*ptr;

	if (*lst == NULL || new == NULL)
		return ;
	ptr = *lst;
	if (!ptr)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return ;
}

void	search(int fd, t_file **files)
{
	t_file	*ptr;
	t_file	*new;

	ptr = *files;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			return ;
		ptr = ptr->next;
	}
	new = malloc(sizeof(t_file));
	new->fd = fd;
	new->store = NULL;
	new->next = NULL;
	ft_lstadd_back(files, new);
}

char	*get_next_line(int fd)
{
	static t_file	*files;
	char			*result;
	char			*store;

	result = NULL;
	if (files == NULL)
	{
		files = malloc(sizeof(t_file));
		files->fd = fd;
		files->store = NULL;
		files->next = NULL;
	}
	search(fd, &files);
	store = ft_adstore(files->store, fd);
	result = ft_strchop(store);
	files->store = new_str(store, &files);
	if (!result)
	{
		ft_strlen2("", 2, &files);
		files = NULL;
	}
	return (result);
}
