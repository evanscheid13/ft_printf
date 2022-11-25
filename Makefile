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

# *****************************************************************
CC        := cc
CFLAGS    := -Wall -Wextra -Werror

# *****************************************************************
RM    := rm -f
AR    := ar rcs
# *****************************************************************
HEADER := ft_printf.h
# *****************************************************************
NAME    := libftprintf.a
SRCS    := ft_hexa.c ft_putnbr.c ft_putstr.c ft_printf.c ft_unsign.c

OBJS    := $(SRCS:.c=.o) 
OBJS_LIBFT	:= $(SRCS_LIBFT:.c=.o)


# *****************************************************************
all:  $(NAME)

test: 
	@ $(CC) $(CFLAGS) main.c $(NAME) -o main
	@ ./main

$(NAME):	$(OBJS)  $(OBJS_LIBFT) 
	@ $(AR) $(NAME) $(OBJS) $(OBJS_LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(OBJS_bonus) $(OBJS_LIBFT) main

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re