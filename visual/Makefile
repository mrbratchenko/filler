# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbratche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 19:51:53 by sbratche          #+#    #+#              #
#    Updated: 2018/02/03 19:51:55 by sbratche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	visual

GCC		=	gcc -Wall -Wextra -Werror

SRC		= ./src/visual.c ./src/projections.c \
		./src/rendering.c ./src/init.c

OBJ		= visual.o key_hooks.o projections.o rendering.o \
		init.o

INC		=	./inc/visual.h

all: 
	$(GCC) $(SRC) -I $(INC) -I /usr/local/include ../libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
