NAME = cub3d

SRC = main.c init_player.c map.c utils.c raycasting.c move.c get_info.c get_textures.c textures.c sprites.c textures2.c\
		draw.c draw_sprites.c check_map.c check_error_map.c read_map.c keys.c ft_screenshot.c

FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) cub3d.h
	gcc libft/libft.a $(SRC) $(FLAGS) -o $(NAME)
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
	gcc libft/libft.a cub3d.h $(SRC) $(FLAGS) -g