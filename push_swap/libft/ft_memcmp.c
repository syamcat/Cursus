/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:32:27 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/08/09 15:26:31 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	bf_s1;
	unsigned char	bf_s2;

	idx = 0;
	while (idx < n)
	{
		bf_s1 = ((unsigned char *)s1)[idx];
		bf_s2 = ((unsigned char *)s2)[idx];
		if (bf_s1 != bf_s2)
			return ((int)(bf_s1 - bf_s2));
		idx++;
	}
	return (0);
}
