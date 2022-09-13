/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:07:45 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 18:19:47 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len_s;
	size_t	idx;

	if (!s)
		return ;
	len_s = ft_strlen(s);
	idx = 0;
	if (fd < 0)
		return ;
	while (idx < len_s)
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	return ;
}
