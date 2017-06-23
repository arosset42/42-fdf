# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosset <arosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 19:01:51 by arosset           #+#    #+#              #
#    Updated: 2016/12/01 13:40:22 by arosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= 	libft.a

CC 			=	gcc
CFLAGS 		= 	-Wall -Werror -Wextra

INCLUDES 	= 	./includes/libft.h

SRC 		= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c      \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c       \
				ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c    \
				ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c    \
				ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c     \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c  \
				ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c 			  \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memalloc.c 	  \
				ft_memdel.c ft_strnew.c ft_strclr.c get_next_line.c				  \
				ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c   \
				ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c    \
				ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c    \
				ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_print_tab.c ft_free_tab.c \
				ft_isupper.c ft_itoa_base.c ft_power.c ft_putwstr.c ft_putwchar.c \
				ft_put_len_str.c ft_put_n_char.c ft_str_index.c ft_uitoa_base.c   \
				ft_convert.c ft_error.c ft_get.c ft_max_str_print.c ft_printf.c   \
				ft_len_print.c ft_print.c ft_undefined.c

OBJ 		= 	$(SRC:.c=.o)

# COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[35m"
C_GOOD		=	"\033[32m"
C_ERROR		= 	"\033[31m"
C_TEST		= 	"\033[33m"

# MESSAGE
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK 			=	$(C_OK)OK$(C_NO)
F_TEST 		= 	$(C_TEST)DEBUT TEST$(C_NO)
ERROR		= 	$(C_ERROR) ERROR $(C_NO)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo [ $(NAME) ] $(SUCCESS)

%.o: %.c ./includes/libft.h
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean, fclean, re
