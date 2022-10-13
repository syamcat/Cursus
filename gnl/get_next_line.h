/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:25:07 by dohyeoki          #+#    #+#             */
/*   Updated: 2022/10/13 20:27:38 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	ft_bnull(void *s, size_t n);
char	*ft_strchop(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*get_next_line(int fd);

#endif
