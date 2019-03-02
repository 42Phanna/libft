# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 03:28:40 by phanna            #+#    #+#              #
#    Updated: 2017/11/09 16:51:28 by phanna           ###   ########.fr        #
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

SRC_PTF_PATH = ./src/ptf/
OBJ_PTF_PATH = ./obj/ptf/
INC_PTF_PATH = ./inc/ptf/

INC_NAME = libft.h

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
ft_str_is_printable.c	get_next_line.c			ft_recur_power_long.c\
ft_ltoa.c				ft_longlen.c			ft_uitoa_base.c\
ft_ultoa.c				ft_ultoa_base.c			ft_uitoa.c\
ft_tomin.c				ft_ftoa.c\

INC_PTF_NAME = ft_printf.h

SRC_PTF_NAME =\
ft_printf.c			ptf_check.c			fill_str.c\
conv_s.c			conv_d.c			conv_p.c\
conv_o.c			conv_u.c			conv_x.c\
conv_x_up.c			conv_x_prec.c		ptf_tools.c\
ptf_tools_o.c		choose_conv.c		ptf_tools_prec.c\
conv_d_prec.c		conv_f.c			conv_o_prec.c\
ptf_tools_x.c		conv_x_up_prec.c	choose_conv2.c\
fill_void_prec_o.c	fill_void_prec_u.c	cmp_fill_x.c\


OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PTF_NAME = $(SRC_PTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC_PTF = $(addprefix $(SRC_PTF_PATH),$(SRC_PTF_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_PTF = $(addprefix $(OBJ_PTF_PATH),$(OBJ_PTF_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
INC_PTF = $(addprefix $(INC_PTF_PATH),$(INC_PTF_NAME))


CC = gcc

CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I$(INC_PATH)
PTFCPPFLAGS = -I$(INC_PTF_PATH)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_PTF)
	@ar rc $(NAME) $(OBJ) $(OBJ_PTF) && ranlib $(NAME)
	@echo "\n${_GREEN}libft generate${_END} [${_GREEN}✔${_END}]"

$(OBJ_PTF_PATH)%.o: $(SRC_PTF_PATH)%.c $(INC_PTF)
	@mkdir $(OBJ_PTF_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(PTFCPPFLAGS) -o $@ -c $<
	@echo "${_PURPLE}█${_END}\c"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
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

.PHONY: all clean fclean re
