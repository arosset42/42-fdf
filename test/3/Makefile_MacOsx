#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_MacOsX                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/16 12:25:58 by lfabbro           #+#    #+#              #
#    Updated: 2017/01/31 21:08:19 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/ ./libft ./minilibx_macos/
LIB_PATH = ./libft/ ./minilibx_macos/

FRAMEWORK = -framework OpenGL -framework Appkit

SRC_NAME =  main.c fdf.c fdf_set.c fdf_complem.c\
			fdf_parse_map.c fdf_get_map.c\
			fdf_draw.c fdf_hook.c fdf_hook2.c\
			fdf_matrix.c fdf_calculate_matrix.c\
			get_next_line.c fdf_errors.c fdf_free.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft -lmlx -lm
NAME = fdf

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast

all: lib
	@echo "\033[35;44m Make $(NAME) \033[0m"
	make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME) $(FRAMEWORK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: all lib clean fclean re

lib:
	@echo "\033[35;44m Make libft \033[0m"
	@make -C ./libft/
	@echo "\033[35;44m Make minilibx \033[0m"
	@make -C ./minilibx_macos/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean
	@make -C ./minilibx_macos/ clean

re: fclean
	@$(MAKE) all
