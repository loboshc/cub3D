NAME = cub3d

SRC = main.c init_player.c map.c utils.c raycasting.c move.c get_info.c get_textures.c textures.c sprites.c textures2.c\
		draw.c draw_sprites.c

FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) cub3d.h
	gcc libft/libft.a cub3d.h $(SRC) $(FLAGS)
run1: $(NAME)
	./a.out map.cub
run2: $(NAME)
	./a.out map2.cub
run3: $(NAME)
	./a.out test.cub
run4: $(NAME)
	./a.out map_test.cub
run5: $(NAME)
	./a.out map2_test.cub
normi:
	norminette $(SRC)
debug:
	gcc libft/libft.a cub3d.h $(SRC) $(FLAGS) -g