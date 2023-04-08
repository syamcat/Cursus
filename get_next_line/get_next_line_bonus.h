/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:25:07 by dohyeoki          #+#    #+#             */
/*   Updated: 2023/04/08 11:53:30 by dohyeoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_file
{
	int				fd;
	char			*store;
	struct s_file	*next;
}				t_file;

size_t	ft_strlen2(char *s, int cased, t_file **lst);
char	*ft_strchr(char *s, int c);
void	ft_bnull(void *s, size_t n);
char	*ft_strchop(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*get_next_line(int fd);

#endif
