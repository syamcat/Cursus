/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:07:45 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/11 17:09:06 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len_s;
	size_t	idx;

	if (!s)
		return (write(1, "(null)", 6));
	len_s = ft_strlen(s);
	idx = 0;
	if (fd < 0)
		return (0);
	while (idx < len_s)
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	return (len_s);
}
