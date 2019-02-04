cmake_minimum_required(VERSION 3.13)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit main.c fillit.h fillit.c libft/ft_strnew.c libft/ft_strjoin.c libft/ft_strdel.c libft/libft.h libft/ft_bzero.c libft/ft_strcat.c libft/ft_strcpy.c libft/ft_strlen.c libft/ft_memset.c libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_memdel.c)