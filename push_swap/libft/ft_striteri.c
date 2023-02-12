/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:44:25 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 15:25:51 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;
	unsigned int	len_s;

	if (s == NULL || f == NULL)
		return ;
	idx = 0;
	len_s = ft_strlen(s);
	while (idx < len_s)
	{
		f(idx, &s[idx]);
		idx ++;
	}
	return ;
}
