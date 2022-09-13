/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:45:39 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 18:17:35 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	idx;
	unsigned int	len_s;

	if (!(s && f))
		return (NULL);
	len_s = ft_strlen(s);
	idx = 0;
	result = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!result)
		return (NULL);
	while (idx < len_s)
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
