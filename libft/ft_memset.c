/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:12:24 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/08/09 15:26:28 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*result;
	size_t			idx;

	idx = 0;
	result = (unsigned char *)b;
	while (idx < len)
	{
		result[idx] = c;
		idx++;
	}
	return (b);
}
