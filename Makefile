# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/28 16:12:12 by hlecuyer          #+#    #+#              #
#    Updated: 2015/03/01 15:28:06 by hlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_2048
VERSION=1.1.0
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./includes -I ./libft/includes
LIBS=-L ./libft -l ft -lncurses -lmenu

SRC=command.c \
	game_logic.c \
	init_grid.c \
	init_ncurses.c \
	main.c \
	main_loop.c \
	fusion.c \
	menu.c \
	check_win.c \
	free_struct.c \
	arrow_command.c \
	next_turn.c

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

