/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:26:46 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/11 17:17:30 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_nb(int nb, int fd, int len)
{
	char	num;

	if (nb >= 10)
	{
		len += ft_print_nb(nb / 10, fd, len);
		nb = nb % 10;
	}
	num = nb + '0';
	write(fd, &num, 1);
	return (len);
	
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		len += write(fd, "-", 1);
		n *= -1;
		len += ft_print_nb(n, fd, 1);
	}
	else
		len += ft_print_nb(n, fd, 1);
	return (len);
}
