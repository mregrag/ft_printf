# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 05:02:23 by mregrag           #+#    #+#              #
#    Updated: 2023/12/12 09:29:36 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c ft_putchar.c ft_putstr.c print_format.c ft_putdigit.c \

OBJS = $(SRCS:.c=.o)
NAME    = libftprintf.a
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
CC		= cc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean 

