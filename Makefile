# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 16:51:49 by abdelilah         #+#    #+#              #
#    Updated: 2025/02/23 02:27:34 by abdelilah        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= check_args.c \
			index.c \
			main.c \
			push_op.c \
			radix.c \
			rev_rot_op.c \
			rotate_op.c \
			simple.c \
			swap_op.c \
			t_list.c \
			utils.c \
			utils1.c \
			utils2.c \
			utils3.c \
			parsing.c \

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c push_swap.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
