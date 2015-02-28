# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/28 10:04:22 by hlecuyer          #+#    #+#              #
#    Updated: 2015/02/28 13:44:17 by fmarmol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_2048
VERSION=1.0.5
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./includes -I ./libft/includes
LIBS=-L ./libft -l ft -lncurses

SRC=main.c \
	init_ncurses.c \
	init_grid.c \
	main_loop.c

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c ./includes ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

