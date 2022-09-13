/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:55:17 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/08/09 15:26:29 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	buffer;
	size_t			idx;

	idx = 0;
	if (dst == src)
		return (dst);
	else if (dst < src)
	{
		while (idx < len)
		{
			buffer = ((unsigned char *)src)[idx];
			((unsigned char *)dst)[idx] = buffer;
			idx++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			buffer = ((unsigned char *)src)[len];
			((unsigned char *)dst)[len] = buffer;
			idx++;
		}
	}
	return (dst);
}
