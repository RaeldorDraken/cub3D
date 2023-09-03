#
#
GREEN			:= \033[32m
BLUE			:= \033[34m
NC				:= \033[m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11


%.o: %.c
	printf "\r$(BLUE)Generating $(NAME) objects... %-38.38s$(NC)" $@
	gcc -c $< -o ${<:.c=.o}

%.o: %.m
	printf "\r$(BLUE)Generating $(NAME) objects... %-38.38s$(NC)" $@
	gcc -c $< -o ${<:.m=.o}

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	printf '\033[1A\033[K'
	@echo "\n$(GREEN)mlx compiled!$(NC)"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(GREEN)mlx cleaned!$(NC)"

re: clean all
