# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 03:28:40 by phanna            #+#    #+#              #
#    Updated: 2017/04/20 14:03:45 by phanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isascii.c ft_memset.c ft_strcmp.c ft_strncmp.c ft_strdup.c\
	  ft_strlen.c ft_tolower.c ft_toupper.c ft_bzero.c ft_strcpy.c ft_strncpy.c\
	  ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_strstr.c ft_strnstr.c\
	  ft_isprint.c ft_strchr.c ft_strrchr.c ft_strcat.c ft_strncat.c\
	  ft_memcpy.c ft_memmove.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	  ft_memalloc.c ft_memdel.c\
	  ft_putchar.c ft_putstr.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC) 
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all
