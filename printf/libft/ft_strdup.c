/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:15:01 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 18:58:47 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		idx;
	int		len_s1;
	char	*result;

	idx = 0;
	len_s1 = ft_strlen(s1);
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
