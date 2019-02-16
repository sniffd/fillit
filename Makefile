# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 15:33:21 by ldonnis           #+#    #+#              #
#    Updated: 2019/02/16 15:11:13 by ldonnis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAG = -Wall -Wextra -Werror -g -ggdb
SRC = main.c fillit.c validate.c getters.c
OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAG) -I libft/includes/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I libft/ -L libft/ -lft

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

.PHONY: all clean fclean re