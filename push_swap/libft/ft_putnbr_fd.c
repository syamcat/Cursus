/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:26:46 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/08 23:41:26 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nb(int nb, int fd)
{
	char	num;

	if (nb >= 10)
	{
		ft_print_nb(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		num = nb + '0';
		write(fd, &num, 1);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_print_nb(n, fd);
	}
	else
		ft_print_nb(n, fd);
}
