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

NAME	=	sbratche.filler

SRC 	=	./src/filler.c ./src/initialize.c ./src/read.c ./src/solve.c

INC		=	./inc

OBJ		= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIBDIR	=	./libft

VISUAL	=	./visual

GCC		=	gcc -Wall -Wextra -Werror

LIBFT 	=	-L $(LIBDIR) -lft

PRINT	=	@echo "\033[32m-\033[0m\c"


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	make -C $(VISUAL)
	$(GCC) $(OBJ) -I $(INC) $(LIBFT) -o $(NAME)

$(OBJDIR)%.o: %.c
	$(GCC) -c $< -o $@  -I $(INC)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)
	make clean -C $(VISUAL)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LIBDIR)
	make clean -C $(VISUAL)

re: fclean all
