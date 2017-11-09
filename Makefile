# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 03:28:40 by phanna            #+#    #+#              #
#    Updated: 2017/11/08 16:37:34 by phanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Colors - Echo

_END = $'\x1b[0m
_GREY = $'\x1b[30m
_RED = $'\x1b[31m
_GREEN = $'\x1b[32m
_YELLOW = $'\x1b[33m
_BLUE = $'\x1b[34m
_PURPLE = $'\x1b[35m
_CYAN = $'\x1b[36m
_WHITE = $'\x1b[37m

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

SRC_NAME =\
ft_atoi.c				ft_memdel.c				ft_striter.c\
ft_bzero.c				ft_memmove.c			ft_striteri.c\
ft_create_elem.c		ft_memset.c				ft_strjoin.c\
ft_factorial.c			ft_numlen.c				ft_strlcat.c\
ft_isalnum.c			ft_power.c				ft_strlen.c\
ft_isalpha.c			ft_putchar.c			ft_strlen_skip_white.c\
ft_isascii.c			ft_putchar_fd.c			ft_strmap.c\
ft_isdigit.c			ft_putendl.c			ft_strmapi.c\
ft_isprint.c			ft_putendl_fd.c			ft_strncat.c\
ft_isspace.c			ft_putnbr.c				ft_strncmp.c\
ft_itoa.c				ft_putnbr_fd.c			ft_strncpy.c\
ft_lstadd.c				ft_putstr.c				ft_strnequ.c\
ft_lstdel.c				ft_putstr_fd.c			ft_strnew.c\
ft_lstdelone.c			ft_sqrt.c				ft_strnstr.c\
ft_lstiter.c			ft_strcat.c				ft_strrchr.c\
ft_lstmap.c				ft_strchr.c				ft_strsplit.c\
ft_lstnew.c				ft_strclr.c				ft_strstr.c\
ft_memalloc.c			ft_strcmp.c				ft_strsub.c\
ft_memccpy.c			ft_strcpy.c				ft_strtrim.c\
ft_memchr.c				ft_strdel.c				ft_tolower.c\
ft_memcmp.c				ft_strdup.c				ft_toupper.c\
ft_memcpy.c				ft_strequ.c				ft_strndup.c\
ft_strlowcase.c			ft_strcapitalize.c		ft_str_is_alpha.c\
ft_str_is_numeric.c		ft_str_is_lowercase.c	ft_str_is_uppercase.c\
ft_str_is_printable.c	get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC = gcc

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -Iinc

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n${_GREEN}libft generate${_END} [${_GREEN}✔${_END}]"
	@ar rc $(NAME) $(OBJ) && ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "${_GREEN}█${_END}\c"

clean:
	@rm -rf $(OBJ_PATH) 
	@echo "${_RED}cleaning objects files${_END} [${_GREEN}✔${_END}]"

fclean: clean
	@rm -f $(NAME)
	@echo "${_RED}delete $(NAME)${_END} [${_GREEN}✔${_END}]"

re: fclean all
