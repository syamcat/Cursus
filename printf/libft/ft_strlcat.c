/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:19:01 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/08 15:38:41 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	offset;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	offset = 0;
	if (len_d >= dstsize)
		return (len_s + dstsize);
	else
	{
		while ((len_d + offset + 1) < dstsize && src[offset])
		{
			dst[len_d + offset] = src[offset];
			offset++;
		}
		dst[len_d + offset] = '\0';
	}
	return (len_d + len_s);
}
