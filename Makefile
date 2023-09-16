# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 17:59:34 by eros-gir          #+#    #+#              #
#    Updated: 2023/09/16 17:50:05 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_YELLOW=\033[0;33m
C_END=\033[0m

NAME = cub3D

SRC = ./srcs/main.c  \
		./libs/gnl/get_next_line.c \
		./srcs/parser/parser.c \
		./srcs/setup/setup.c \
		./srcs/display/display.c \
		./srcs/interactive/interactive.c \
		./srcs/validations/validations.c \
		./srcs/destroyer/destroyer.c \
		./srcs/utils/utils1.c \
		./srcs/utils/utils2.c \
		./srcs/helpers/player/player_helpers_1.c \
		./srcs/helpers/player/player_helpers_2.c \

HDR = ./libs/libft/libft.h ./incl/cube.h ./libs/mlx/mlx.h Makefile

LIBFTDIR = ./libs/libft/
MLXDIR = ./libs/mlx/

OBJ = $(SRC:.c=.o)

GC = gcc 
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -L $(LIBFTDIR) -lft
MFLAGS = -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HDR)
	@$(GC) $(CFLAGS) -o $@ -c $<

all: make_lib make_mlxlib $(NAME)

make_lib:
	@echo "$(C_YELLOW)make libft...$(C_END)"
	@make -C $(LIBFTDIR)

make_mlxlib:
	@echo "$(C_YELLOW)make mlxlib...$(C_END)"
	@make -C $(MLXDIR)

$(NAME): $(OBJ) $(HDR) libs/libft/libft.a libs/mlx/libmlx.a
	@echo "$(C_YELLOW)make cub3D...$(C_END)"
	$(GC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(MFLAGS)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

clean:
	@echo "$(C_RED)cleaning *.o$(C_END)"
	make clean -s -C $(LIBFTDIR)
	make clean -s -C $(MLXDIR)
	rm -f $(OBJ)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

fclean: clean
	@echo "$(C_RED)cleaning executable$(C_END)"
	make fclean -s -C $(LIBFTDIR)
	make clean -s -C $(MLXDIR)
	rm -f $(NAME)
	@echo "$(C_GREEN)FINISHED!$(C_END)"

re: fclean all
	@echo "$(C_GREEN)Recompiled!$(C_END)"