/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:32:34 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/08 15:03:30 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	idx;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	idx = ft_strlen(&s[start]);
	if (idx < len)
		len = idx;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
