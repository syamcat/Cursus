/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:57:36 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/01/25 18:04:03 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
