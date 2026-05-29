# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 13:27:22 by vde-alme          #+#    #+#              #
#    Updated: 2026/05/29 19:44:44 by vde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
HEADER 	= libft.h

SRCS	= ft_bzero.c ft_memset.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -rf $() $(OBJS)

fclean: clean
rm -f $(NAME)

re: fclean all

test_%: %.c $(HEADER)
@$(CC) $(CFLAGS) $< -o test_exec
@./test_exec "Test" || True
@rm -f test_exec

.PHONY: all clean fclean re