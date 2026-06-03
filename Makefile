# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: v <v@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 13:27:22 by vde-alme          #+#    #+#              #
#    Updated: 2026/06/02 22:27:27 by v                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
HEADER 	= libft.h

SRCS	= ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c  ft_strlen.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_toupper.c ft_tolower.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c 


OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re