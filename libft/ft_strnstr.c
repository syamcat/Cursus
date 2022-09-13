/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:50:28 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/08 23:42:44 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	idx_n;

	idx = 0;
	idx_n = 0;
	if (!(needle[0]))
		return ((char *)haystack);
	while (haystack[idx] && idx < len)
	{
		idx_n = 0;
		while (needle[idx_n] == haystack[idx + idx_n] \
		&& haystack[idx + idx_n] && idx + idx_n < len)
		{
			if (!(needle[idx_n + 1]))
				return (&((char *)haystack)[idx]);
			idx_n++;
		}
		idx++;
	}
	return (0);
}
