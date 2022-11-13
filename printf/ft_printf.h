/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:33:33 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/11/13 16:34:14 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef unsigned long long	t_ull;

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(t_ull nbr, char *base);
int	ft_prt_pnt(t_ull p, char *base);

#endif