/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:14 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/11 17:24:46 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_putunbr_fd(unsigned int nb, int fd, int len)
{
	char	num;

	if (nb >= 10)
	{
		len += ft_putunbr_fd(nb / 10, fd, len);
		nb = nb % 10;
	}
	num = nb + '0';
	write(fd, &num, 1);
	return (len);
}
