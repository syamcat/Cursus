# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyeoki <dohyeoki@student@42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 17:29:12 by dohyeoki          #+#    #+#              #
#    Updated: 2022/11/13 15:57:30 by dohyeoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ./ft_printf.h

SRCS =	ft_printf.c ft_conv_s.c

OBJS = $(SRCS:.c=.o)

DIR_LIB = ./libft

LIB = ./libft/libft.a

all:	$(NAME)

$(NAME):	$(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar -rc $@ $(OBJS) 

$(LIB) :
	make -C $(DIR_LIB) all

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
	make -C $(DIR_LIB) clean
	rm -rf $(OBJS)

fclean:	clean
	make -C $(DIR_LIB) fclean
	rm -f $(NAME)

re:	fclean
	make all

.PHONY:	all clean fclean re bonus
