/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:49:52 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/08/09 15:26:16 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] || s2[idx]) && idx < n)
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		else
			idx++;
	}
	return (0);
}
