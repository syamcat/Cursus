/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:25:07 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/27 22:25:52 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);
static char	*ft_strchr(const char *s, int c);
static char	*ft_strndup(char *s1, int n);
static char	*ft_strchop(char *str);
static char	*ft_strjoin(char *str, char *buff);
char	*get_next_line(int fd);
char *new_str(char *s);

#endif
