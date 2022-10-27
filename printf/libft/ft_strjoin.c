/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:40:32 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 18:10:36 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
