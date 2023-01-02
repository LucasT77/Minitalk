# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/01/02 16:46:53 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=	client
SERVER			=	server

SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)
CLIENT_SRC		=	client.c
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

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

clean:
						$(MAKE) clean -C libft
						$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:			clean
						$(RM) $(SERVER) $(CLIENT)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
