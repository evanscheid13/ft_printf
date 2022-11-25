# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:28:18 by marvin            #+#    #+#              #
#    Updated: 2022/11/25 20:28:18 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_hexa.c ft_putnbr.c ft_putstr.c ft_printf.c ft_unsign.c ft_intlen.c ft_putchar.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean