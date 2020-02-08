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

NAME = filler
INCLUDES := -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)
CFLAGS := -Wall -Wextra -Werror
LIB_FLAG := -L $(LIBFT_DIR) -lftprintf

LIBFT_DIR = ft_printf/
LIBFT = $(LIBFT_DIR)libftprintf.a
LIBFT_HEADERS = $(LIBFT_DIR)includes/

HEADERS_DIR = includes/
HEADERS_LST = filler.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LST))

SRCS_DIR = srcs/
SRCS_LST = filler_main.c parse.c logic.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJ_DIR = objects/
OBJ_LST =  $(patsubst %.c, %.o, $(SRCS_LST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LST))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(CFLAGS) $(INCLUDES) $(LIB_FLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	gcc $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)
	
clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
