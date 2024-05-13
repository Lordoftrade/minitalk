# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 15:01:57 by mgreshne          #+#    #+#              #
#    Updated: 2024/04/14 15:59:36 by mgreshne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
PRINTF = ./ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERV_SRCS = server.c
SERV_OBJS = $(SERV_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERV_BONUS_SRCS = server_bonus.c
SERV_BONUS_OBJS = $(SERV_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(PRINTF):
	$(MAKE) -C ./ft_printf
$(SERVER): $(SERV_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(SERV_OBJS) $(PRINTF) -o server
$(CLIENT): $(CLIENT_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(PRINTF) -o client

$(SERVER_BONUS): $(SERV_BONUS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(SERV_BONUS_OBJS) $(PRINTF) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(PRINTF) -o client_bonus

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SERV_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERV_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: all clean fclean re
