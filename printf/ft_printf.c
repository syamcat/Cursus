/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:24 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/11 18:06:02 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

// void	ft_putchar_fd(char c, int fd)
// {
// 	if (fd < 0)
// 		return ;
// 	write(fd, &c, 1);
// 	return ;
// }
// 여기 위로 test

int	ft_checkbase(char *base)
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

int	ft_prtnbr_base(unsigned long long nbr, char *base, unsigned int b_len, int len)
{
	if (nbr >= b_len)
	{
		len += ft_prtnbr_base(nbr / b_len, base, b_len, len);
		nbr = nbr % b_len;
	}
	write(1, &base[nbr], 1);
	return (len);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	i;
	int	base_len;
	int len;

	i = 0;
	len = 0;
	if (ft_checkbase(base))
		return (len);
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		len += ft_prtnbr_base(nbr * -1, base, base_len, 1);
	}
	else
		len += ft_prtnbr_base(nbr, base, base_len, 1);
	return (len);
}

int	ft_print_pointer(unsigned long long p, char *base)
{
	write(1, "0x", 2);
	return (ft_putnbr_base(p, base) + 2);
}

int	ft_print_conv(va_list *ap, char *org, int *i, int len)
{
	if (org[*i + 1] == 'c')
		len += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (org[*i + 1] == 's')
		len += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (org[*i + 1] == 'p')
		len += ft_print_pointer(va_arg(*ap, unsigned long long), "0123456789abcdef");
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
	// write(1, result, sizeof(result));
	return (len);
}

// int main(void)
// {
// 	int	len1;
// 	int len2;
// 	len1 = ft_printf("%sthis is correct?\n %p\n", "well... ", "");
// 	len2 = printf("%sthis is correct?\n %p\n", "well... ", "");
// 	printf("len: %d\n", len1);
// 	printf("len2: %d\n", len2);
// 	return 0;
// }