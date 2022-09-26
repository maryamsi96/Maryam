# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 18:33:08 by msaleh            #+#    #+#              #
#    Updated: 2022/09/26 18:32:19 by msaleh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

LIBFT_DIR	=	libft1
LIBFT		=	$(LIBFT_DIR)/libftprintf.a

INC_DIR		=	.
SRC_DIR		=	.

SRC_CLIENT	=	client.c
OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)
SRC_SERVER	=	server.c
OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:			$(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
				make -C $(LIBFT_DIR) all

$(CLIENT):		$(OBJ_CLIENT)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) -o client $(LIBFT)

$(SERVER):		$(OBJ_SERVER)
				$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ $(LIBFT)

bonus:			all

clean:
				make -C $(LIBFT_DIR) fclean
				@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
				
fclean:			clean
				@$(RM) $(CLIENT) $(SERVER)

re:				fclean all

norm:
				@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/*.c
				@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c
				@norminette -R CheckDefine $(INC_DIR)/*.h

.PHONY:			all bonus clean fclean re norm