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
FLAGS			=	-Wall -Wextra -Werror

LIB_MLX			=	./minilibx_macos
MLX 			=	./minilibx_macos/libmlx.a

LIB_PATH		= 	./libft/
LIB				=	./libft/libft.a
LIB_LINK		=	./libft/libft.a

INC_PATH		= 	./includes
SRC_PATH		=	./src
SRC_NAME 		= 	fdf.c error.c parser.c ft_utility.c ft_hook.c ft_draw.c\
					ft_calc.c ft_matrice.c color.c ft_display.c
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
	@echo "Exec =>"$(YELLOW) $(NAME) $(RESET): $(SUCCESS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<
	@echo "Obj" [ $< ] $(OK)


$(LIB):
	@make -C $(LIB_PATH)
	@make -C $(LIB_MLX)

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo $(DELETE) : $(OBJ) $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@echo $(DELETE_LIB) : Obj Libft
	@make -C $(LIB_MLX) clean
	@echo $(DELETE_LIB) : Obj MLX


fclean: clean
	@rm -rf $(NAME)
	@echo $(DELETE) : $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo $(DELETE_LIB) : Lib

re: fclean all
