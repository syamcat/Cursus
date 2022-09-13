/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:28:03 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/06 17:52:12 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	idx;
	int	sign;

	result = 0;
	idx = 0;
	sign = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (result > 214748364 && ((str[idx] - '0') * sign > 7))
			return (-1);
		if (result < -214748364 && ((str[idx] - '0') * sign < -8))
			return (0);
		result = (result * 10) + ((str[idx] - '0') * sign);
		idx++;
	}
	return (result);
}
