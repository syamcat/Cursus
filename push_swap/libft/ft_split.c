/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:08:20 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/08 23:42:11 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **result, int i)
{
	int	idx;

	idx = 0;
	while (idx <= i)
	{
		free(result[idx]);
		idx++;
	}
	free(result);
	return ;
}

static int	ft_count_word(char const *str, char sepa)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sepa && str[i])
			i++;
		if (str[i] != sepa && str[i])
			count++;
		while (str[i] != sepa && str[i])
			i++;
	}
	return (count);
}

static char	*ft_write_word(char *copy, char const *str, char charset)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (str[j] == charset && str[j])
		j++;
	while (str[j + word_len] != charset && str[j + word_len])
		word_len++;
	copy = (char *)malloc(sizeof(char) * (word_len + 1));
	if (copy == NULL)
		return (0);
	while (str[i] != charset && str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	ft_write_split(char const *s, char **result, char c, int word)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < word)
	{
		while (s[j] == c && s[j])
			j++;
		result[i] = ft_write_word(result[i], &s[j], c);
		if (!result[i])
		{
			ft_free(result, i);
			return ;
		}
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	result[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (NULL);
	ft_write_split(s, result, c, word);
	return (result);
}
