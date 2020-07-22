/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:17:36 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/22 10:13:20 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_args(int argc, char **argv, t_mlx *mlx)
{
	if (argc != 2)
	{
		if (argc == 1)
		{
			ft_putstr_fd("No hay mapa: ./cub3d [map.cub]", 1);
			exit(EXIT_FAILURE);
			return (1);
		}
		else if (argc == 3 && (ft_strncmp("--save", argv[2],
				ft_strlen(argv[2])) == 0))
		{
			init_values(mlx);
			get_info(argv[1], mlx);
			mlx->zbuffer = (double*)malloc(sizeof(double) * mlx->s_width);
			init_mlx(mlx);
			textures(mlx);
			ft_raycasting(mlx);
			ft_screen_shot(mlx);
		}
		else
			error_exit("Argumento invalido.");
	}
	else if ((ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) == NULL)
		error_exit("El mapa debe tener la extension [.cub].");
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	int h;
	int w;

	h = mlx->s_height;
	w = mlx->s_width;
	mlx->mlx = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx, w, h, "CUB3D");
}

void	init_value2(t_mlx *mlx)
{
	int i;

	mlx->path_north = NULL;
	mlx->path_south = NULL;
	mlx->path_east = NULL;
	mlx->path_west = NULL;
	mlx->path_sprite = NULL;
	mlx->move_speed = MOVE_SPEED;
	mlx->sprite_num = 0;
	mlx->f = 0;
	mlx->x = 0;
	mlx->sky.r = 0;
	mlx->sky.g = 0;
	mlx->sky.b = 0;
	mlx->floor.r = 0;
	mlx->floor.g = 0;
	mlx->floor.b = 0;
	mlx->read_map = 0;
	mlx->s_width = 0;
	mlx->s_height = 0;
	mlx->p = 0;
	mlx->m_y = 0;
	i = 0;
	while (i < 100)
		mlx->max_width[i++] = 0;
}

void	init_values(t_mlx *mlx)
{
	mlx->cameraX = 0;
	mlx->rayDirX = 0;
	mlx->rayDirY = 0;
	mlx->mapX = 0;
	mlx->mapY = 0;
	mlx->sideDistX = 0;
	mlx->sideDistY = 0;
	mlx->stepX = 0;
	mlx->stepY = 0;
	mlx->deltaDistX = 0;
	mlx->deltaDistY = 0;
	mlx->hit = 0;
	mlx->side = 0;
	mlx->move_w = 0;
	mlx->move_s = 0;
	mlx->move_a = 0;
	mlx->move_d = 0;
	mlx->move_rr = 0;
	mlx->move_rl = 0;
	mlx->m_height = 0;
	mlx->m_width = 0;
	init_value2(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	check_args(argc, argv, &mlx);
	init_values(&mlx);
	get_info(argv[1], &mlx);
	mlx.zbuffer = (double*)malloc(sizeof(double) * mlx.s_width);
	init_mlx(&mlx);
	textures(&mlx);
	mlx_loop_hook(mlx.mlx, ft_raycasting, &mlx);
	mlx_hook(mlx.mlx_window, KEY_PRESS, (1L << 0), key_pressed, &mlx);
	mlx_hook(mlx.mlx_window, KEY_RELEASE, (1L << 1), key_release, &mlx);
	mlx_hook(mlx.mlx_window, 17, 0, exit_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
