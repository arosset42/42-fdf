# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 14:08:14 by arosset           #+#    #+#              #
#    Updated: 2017/06/23 14:08:17 by arosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			= 	fdf

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -g

LIB_MLX			=	./minilibx_macos
MLX 			=	./minilibx_macos/libmlx.a

LIB_PATH		= 	./libft/
LIB				=	./libft/libft.a
LIB_LINK		=	./libft/libft.a

INC_PATH		= 	./includes
SRC_PATH		=	./src
SRC_NAME 		= 	fdf.c error.c parser.c ft_utility.c ft_hook.c ft_draw.c
OBJ_PATH		=	./obj

OBJ_NAME		=	$(SRC_NAME:.c=.o)

INC_NAME		=	fdf.h

OBJ 			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# COLORS
RESET			=	"\033[00m"
RED				=	"\033[31m"
GREEN			=	"\033[32m"
YELLOW			=	"\033[33m"
BLUE			= 	"\033[34m"
PURPLE			=	"\033[35m"

# MESSAGE
SUCCESS			=	$(GREEN)SUCCESS$(RESET)
OK				=	$(PURPLE)OK$(RESET)
DELETE			=	$(RED)DELETE$(RESET)
DELETE_LIB		=	$(RED)DELETE LIB$(RESET)
TEST 			= 	$(YELLOW)DEBUT TEST$(RESET)


all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(LIB_LINK) $(FLAGS) $(OBJ) $(MLX) -framework OpenGL -framework AppKit -o $@
	@echo $(RED)"Exec =>"$(YELLOW) $(NAME) : $(SUCCESS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<
	@echo "Obj" [ $< ] $(OK)


$(LIB):
	@make -C $(LIB_PATH)
	@make -C $(LIB_MLX)

test: all
	./fdf maps/42.fdf

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo $(DELETE) : $(OBJ) $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@echo $(DELETE_LIB) : Obj_Lib

fclean: clean
	@rm -rf $(NAME)
	@echo $(DELETE) : $(NAME)
	#@make -C $(LIB_PATH) fclean
	#@echo $(DELETE_LIB) : Lib

re: fclean all


#printf("y [%d] = %f, x [%d] = %f z = %f\n", i, screen->map->lines[i]->points[j]->y, j, screen->map->lines[i]->points[j]->x,screen->map->lines[i]->points[j]->z);
