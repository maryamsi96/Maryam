# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 17:31:48 by msaleh            #+#    #+#              #
#    Updated: 2022/09/22 20:32:34 by msaleh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_parser.c ft_printf.c ft_address.c ft_hex.c ft_atoi.c \
					ft_putchar.c ft_putnbr_u.c ft_putnbr.c ft_putstr.c  
					
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
