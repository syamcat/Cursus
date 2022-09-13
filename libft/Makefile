# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 20:04:18 by juneykim          #+#    #+#              #
#    Updated: 2022/09/08 23:43:17 by dohyeoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADER = ./libft.h

SRCS =	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
SRCS_BONUS =	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef CUNDUCT_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all:	$(NAME)

bonus: 
	make CUNDUCT_BONUS=1 all

$(NAME):	$(OBJ_FILES)
	ar -rc $@ $^ $(HEADER)
	
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -f $(NAME) $(OBJS_BONUS)

re:	fclean
	make all

.PHONY:	all clean fclean re bonus
