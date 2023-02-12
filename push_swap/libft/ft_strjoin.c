/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:40:32 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/01/23 04:31:40 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
