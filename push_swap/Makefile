# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyeoki <dohyeoki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 21:39:46 by dohyeoki          #+#    #+#              #
#    Updated: 2023/02/19 18:36:12 by dohyeoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
# CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

LIB_DIR		=	./libft/
LIB			=	libft.a

NAME	=	push_swap

SRCS	=	push_swap.c list.c operations.c error.c sort_ascending.c sort_descending.c test_sort.c
INSC	=	push_swap.h

all	:	$(LIB) $(NAME)

$(LIB)	:
		make -C $(LIB_DIR) bonus

$(NAME)	:
		$(CC) -o $@ -L$(LIB_DIR) -lft -I push_swap.h $(SRCS) -g3 -fsanitize=address

clean	:
		make -C $(LIB_DIR)	clean

fclean	:
		rm -rf $(NAME)
		make -C $(LIB_DIR)	fclean

re		: fclean
		make all

.PHONY:	all clean fclean re