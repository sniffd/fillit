# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 15:33:21 by ldonnis           #+#    #+#              #
#    Updated: 2019/02/17 04:52:41 by ldonnis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = main.c fillit.c validate.c getters.c map.c coords.c list.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAG) -I libft/includes/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I libft/ -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re:	fclean all