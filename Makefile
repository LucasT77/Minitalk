# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/01/03 18:17:24 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=	client
SERVER			=	server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus

SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)
CLIENT_SRC		=	client.c
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

SERVER_BONUS_SRC		=	server_bonus.c
SERVER_BONUS_OBJ		=	$(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_SRC		=	client_bonus.c
CLIENT_BONUS_OBJ		=	$(CLIENT_BONUS_SRC:.c=.o)

LIBFT			=	libft/libft.a
CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f


all:			$(SERVER) $(CLIENT) 
$(LIBFT):
						$(MAKE) -C libft
$(SERVER):		$(SERVER_OBJ) $(LIBFT)
						$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o server
$(CLIENT):		$(CLIENT_OBJ) $(LIBFT)
						$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o client

bonus:			all		$(SERVER_BONUS) $(CLIENT_BONUS)
$(SERVER_BONUS):		$(SERVER_BONUS_OBJ) $(LIBFT)
						$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o server_bonus
$(CLIENT_BONUS):		$(CLIENT_BONUS_OBJ) $(LIBFT)
						$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o client_bonus

clean:
						$(MAKE) clean -C libft
						$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
						$(RM) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean:			clean
						$(MAKE) fclean -C libft
						$(RM) $(SERVER) $(CLIENT)
						$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re:				fclean all
