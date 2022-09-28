/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:25:07 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/09/28 23:40:31 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		ft_bnull(void *s, size_t n);
char		*ft_strchop(char *str);
char		*ft_strjoin(char *str, char *buff);
static char		*new_str(char *s);
char			*get_next_line(int fd);

#endif
