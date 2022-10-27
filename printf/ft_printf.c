/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:04:17 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/10/24 21:22:03 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "./libft/libft.a"
#include <stdio.h>
// #define ft_printf(...) ft_printf(__VA_ARGS__, NULL)


// 서식지정자(%)들 인자값으로 바꾸기
// char	*ft_rewrite(char *, void *);

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}


char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	if (!s || !c)
		return NULL;
	idx = 0;
	len = ft_strlen(s);
	// printf("here\n");
	while (idx <= len)
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	return (0);
}

int	ft_count_conv(const char *str)
{
	int		count;
	int		idx;
	char	*conv;

	count = 0;
	idx = 0;
	conv = "cspdiuxX%";
	while(str[idx])
	{
		if (str[idx] == '%')
		{
			if (!str[++idx])
				return (count);
			if (ft_strchr(conv, str[idx]))
				count++;
			else
				continue ;
		}
		else
			idx++;
	}
	return (count);
}

// 서식지정자는 cspdiuxX%
int ft_printf(const char *str, ...)
{
	char	*org;
	char	*par;
	va_list ap;
	int		count;

	org = (char *)str;
	// printf("%s\n", org);
	par = (char *)str;
	printf("%s\n", par);
	count = ft_count_conv(org);
	printf("count: %d\n", count);
	va_start(ap, str);
	while (count--) // 문자열에서 읽어온 %붙어있는 것들 개수
	{
		par = va_arg(ap, char *);
		printf("%s\n", par);
	}
	va_end(ap);
	return 0;
}

int main(void)
{
	ft_printf("%dthis %dis correct?", "%d", "%swell");
	return 0;
}