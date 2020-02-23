# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorcros <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 02:16:22 by snorcros          #+#    #+#              #
#    Updated: 2020/02/08 02:16:23 by snorcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = snorcros.filler
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = ft_printf/
LIBFT = $(LIBFT_DIR)libftprintf.a
LIBFT_HEADERS = $(LIBFT_DIR)includes/
LIB_FLAG := -L./$(LIBFT_DIR) -lftprintf

HEADERS_DIR = includes/
HEADERS_LST = filler.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LST))
INCLUDES := -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

SRCS_DIR = srcs/
SRCS_LST =  filler.c parse.c logic.c new_structs.c piece.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJ_DIR = objects/
OBJ_LST = $(patsubst %.c, %.o, $(SRCS_LST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LST))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(INCLUDES) $(LIB_FLAG) -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

objects/%.o : srcs/%.c $(HEADERS)
	gcc $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
