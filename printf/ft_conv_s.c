/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:52:03 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/13 16:36:49 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_prt_num(t_ull nbr, char *base, unsigned int b_len, int len)
{
	if (nbr >= b_len)
	{
		len += ft_prt_num(nbr / b_len, base, b_len, len);
		nbr = nbr % b_len;
	}
	write(1, &base[nbr], 1);
	return (len);
}

int	ft_putnbr_base(t_ull nbr, char *base)
{
	int	i;
	int	base_len;
	int	len;

	i = 0;
	len = 0;
	if (ft_checkbase(base))
		return (len);
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		len += ft_prt_num(nbr * -1, base, base_len, 1);
	}
	else
		len += ft_prt_num(nbr, base, base_len, 1);
	return (len);
}

int	ft_prt_pnt(t_ull p, char *base)
{
	write(1, "0x", 2);
	return (ft_putnbr_base(p, base) + 2);
}
