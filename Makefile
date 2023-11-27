# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 13:47:39 by rcarbonn          #+#    #+#              #
#    Updated: 2023/11/09 17:35:53 by rcarbonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM	= rm -rf
CC	= cc
FL	= -Wall -Werror -Wextra
COMP	= $(CC) $(FL)

# -- SRC -- #

SRCC	= 	srcs/client/client.c
SRCS	=	srcs/server/server.c srcs/server/ft_realloc.c

LIBFT_DIR = ./include/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) server client

$(LIBFT):
	make -C $(LIBFT_DIR)

client:
	$(CC) $(FL) $(SRCC) $(LIBFT) -o client
	
server:
	$(CC) $(FL) $(SRCS) $(LIBFT) -o server

clean:
	$(RM) server client
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) server client
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY: all clean fclean re