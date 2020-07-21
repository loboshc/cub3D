NAME = cub3D

SRC = srcs/main.c srcs/init_player.c srcs/map.c srcs/utils.c srcs/raycasting.c srcs/move.c srcs/get_info.c srcs/get_textures.c srcs/textures.c srcs/sprites.c srcs/textures2.c\
		srcs/draw.c srcs/draw_sprites.c srcs/check_map.c srcs/check_error_map.c srcs/read_map.c srcs/keys.c srcs/ft_screenshot.c

OBJS  = $(SRC:.c=.o)

CC = @gcc

CFLAGS = -W -Wall -Wextra -Werror -I minilibx -I headers -I libft
FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
make_libft:
	@make -C libft/
$(NAME): make_libft $(OBJS) 
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
run1: $(NAME)
	./$(NAME) map.cub
run2: $(NAME)
	./$(NAME) map2.cub
run3: $(NAME)
	./$(NAME) test.cub
run4: $(NAME)
	./$(NAME) map_test.cub
run5: $(NAME)
	./$(NAME) map2_test.cub
normi:
	norminette $(SRC)
debug:
	$(CC) $(CFLAGS) $(FLAGS) $(SRC) libft/libft.a -g
clean:
	@rm srcs/*.o
	@make clean -C libft/
fclean: clean
	@rm $(NAME)
	@make fclean -C libft/
re : fclean all