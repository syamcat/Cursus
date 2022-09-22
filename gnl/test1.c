/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:18:15 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/22 21:56:01 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int	ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx <= len)
	{
		if (s[idx] == (char)c)
			return (idx);
		idx++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, int n)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (result);
}

int main(void)
{
	char		*result;
	static char	*tmp;
	char		buff[BUFFER_SIZE];
	int			fd;
	ssize_t		rd_size;

	result = ft_strndup("", 0);
	tmp = ft_strndup("", 0);
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		while (0 < (rd_size = read(fd, buff, BUFFER_SIZE - 1)))
		{
			buff[rd_size] = '\0';
			printf("%s\n", buff);
			if (!ft_strchr(buff, '\n'))
				tmp = ft_strjoin(tmp, buff);
			else 
			{
				tmp = ft_strjoin(tmp, ft_strndup(buff, ft_strchr(buff, '\n') + 1));
				result = ft_strjoin(result, tmp);
				if (buff[BUFFER_SIZE - 1] != '\n')
					tmp = ft_strndup(ft_strrchr(buff, '\n') + 1, ft_strlen(ft_strrchr(buff, '\n')));
			}
		}
		result = ft_strjoin(result, tmp);
		close (fd);
	}	
	else
		printf("fail");
	printf("---------------this is result---------------\n%s\n", result);
	return 0;
}
