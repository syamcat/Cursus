/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:24 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/13 16:37:33 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_conv(va_list *ap, char *org, int *i, int len)
{
	if (org[*i + 1] == 'c')
		len += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (org[*i + 1] == 's')
		len += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (org[*i + 1] == 'p')
		len += ft_prt_pnt(va_arg(*ap, t_ull), "0123456789abcdef");
	else if (org[*i + 1] == 'd')
		len += ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (org[*i + 1] == 'i')
		len += ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (org[*i + 1] == 'u')
		len += ft_putunbr_fd(va_arg(*ap, unsigned int), 1, 1);
	else if (org[*i + 1] == 'x')
		len += ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef");
	else if (org[*i + 1] == 'X')
		len += ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	else if (org[*i + 1] == '%')
		len += write(1, "%", 1);
	else
		return (0);
	*i = *i + 1;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char	*org;
	int		i;
	int		len;
	va_list	ap;

	org = (char *)str;
	i = 0;
	len = 0;
	va_start(ap, str);
	while (org[i])
	{
		if (org[i] == '%')
			len += ft_print_conv(&ap, org, &i, 0);
		else
			len += write(1, &org[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
