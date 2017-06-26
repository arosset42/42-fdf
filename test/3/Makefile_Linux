#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Linux                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/16 12:24:26 by lfabbro           #+#    #+#              #
#    Updated: 2016/04/16 12:29:20 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/ ./libft/ ./libft/includes/  ./minilibx/
LIB_PATH = ./libft/ ./minilibx/

FRAMEWORK = -lXext -lX11 -lm

SRC_NAME = fdf.c fdf_calculate_matrix.c fdf_complem.c\
		   fdf_draw.c fdf_errors.c fdf_free.c fdf_get_map.c\
		   fdf_hook.c fdf_hook2.c fdf_matrix.c fdf_parse_map.c\
		   fdf_set.c get_next_line.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft -lmlx
NAME = fdf

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast

all: lib
	@echo -e "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME) $(FRAMEWORK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< $(LIB) $(LIB_NAME)

.PHONY: lib clean fclean re

lib:
	@echo -e "\033[37;44m Make libft \033[0m"
	@make -C ./libft/
	@echo -e "\033[37;44m Make minilibx \033[0m"
	@make -C ./minilibx/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean
	@make -C ./minilibx/ clean

re: fclean
	@$(MAKE) all
