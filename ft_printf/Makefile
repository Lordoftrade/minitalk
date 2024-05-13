# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 17:09:44 by mgreshne          #+#    #+#              #
#    Updated: 2024/04/14 17:11:10 by mgreshne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_transform_print.c ft_itoa.c ft_print_char.c \
		ft_print_int.c ft_print_p.c ft_print_string.c \
		ft_print_unsigned_int.c ft_printf.c ft_strlen.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJ = $(SRCS:.c=.o)
INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
