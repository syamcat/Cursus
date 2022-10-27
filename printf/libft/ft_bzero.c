/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:42:02 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 16:01:56 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*result;
	size_t			idx;

	idx = 0;
	if (n == 0)
		return ;
	else
	{
		result = (unsigned char *)s;
		while (idx < n)
		{
			result[idx] = 0;
			idx++;
		}
	}
	return ;
}
