/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:23:22 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 19:26:59 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_input_num(char *str, int num, int len)
{
	int	div;
	int	idx;

	div = 1;
	idx = 0;
	while (--len > 0)
		div *= 10;
	if (num < 0)
	{
		str[idx] = '-';
		idx++;
		div *= -1;
	}
	while (div != 0)
	{
		str[idx] = (num / div) + '0';
		num = num - ((num / div) * div);
		idx++;
		div /= 10;
	}
	str[idx] = '\0';
	return ;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		idx;
	int		len;
	int		sign;

	sign = 0;
	len = ft_intlen(n);
	idx = 0;
	if (n < 0)
		sign = 1;
	result = (char *)malloc(sizeof (char) * (len + sign + 1));
	if (!result)
		return (NULL);
	ft_input_num(result, n, len);
	return (result);
}
