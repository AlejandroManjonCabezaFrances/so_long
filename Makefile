# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 12:50:26 by amanjon-          #+#    #+#              #
#    Updated: 2023/08/02 11:07:03 by amanjon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I /libft/ft_printf/include -I /libft/gnl/include -I /libft/Libft/include
MLX = ./mlx/libmlx.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
DEBUG =#-g3 -fsanitize=address
RM = rm -f
SRC = main.c map.c  map2.c utils.c check_error.c key_hooks.c move_player.c check_path.c 

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

##########RULES##########
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)

$(LIBFT): $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)

# $(MLX) : $(MLX_PATH)
# 	@make -sC $(MLX_PATH)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

##########basic library compiled##########
$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

##########all .o files removed##########
clean:
		$(RM) $(OBJ)
		make clean -C libft
		rm -rf $(OBJ_DIR)

##########library .a file removed##########
fclean: clean
		$(RM) $(NAME)
		make fclean -C libft
		rm -rf $(OBJ_DIR)

re:	fclean all

.PHONY:	all clean fclean re