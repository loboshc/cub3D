/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:17:36 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/21 19:00:14 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
		{
			ft_putstr_fd("Error\nNo hay mapa: ./cub3d [map.cub]", 1);
			exit(EXIT_FAILURE);
			return (1);
		}
		else if (argc == 3)
		{
			//CONDICION PARA --SAVE
		}
	}
	return (0);
}

void	get_resolution(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->s_width = 0;
	mlx->s_height = 0;
	while(line[i] == 'R' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->s_width = mlx->s_width * 10 + line[i] - '0';
		i++;
	}
	while(line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->s_height = mlx->s_height * 10 + line[i] - '0';
		i++;
	}
}

void	get_info(char *argv, t_mlx *mlx)
{
	int fd;
	char *line;
	int lastline;

	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit("Error\nEl mapa no existe o no se encuentra");
	while((lastline = get_next_line(fd, &line)) >= 0)
	{
		if (*line == 'R')
			get_resolution(line, mlx);
		else if (*line == 'N' || *line == 'S'|| *line == 'W' || *line == 'E')
			get_textures(mlx, line);
		else if (*line == 'F')
			get_color_f(mlx, line);
		else if (*line == 'C')
			get_color_s(mlx, line);
		else if (*line == '1')
			get_info_map(line, mlx, lastline);
		else if (ft_isdigit(*line))
			error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
		free_and_null((void*)line);
		if (!lastline)
			break ;
	}
	close(fd);
}


void 	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->s_width, mlx->s_height, "CUB3D");
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
	mlx->path_north = NULL;
	mlx->path_south = NULL;
	mlx->path_east = NULL;
	mlx->path_west = NULL;
	mlx->path_sprite = NULL;
}

int		key_pressed(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		exit(0);
	}
	if (key == KEY_W)
		mlx->move_w = 1;
	if (key == KEY_S)
		mlx->move_s = 1;
	if (key == KEY_LEFT)
		mlx->move_rl = 1;
	if (key == KEY_RIGHT)
		mlx->move_rr = 1;
	if (key == KEY_A)
		mlx->move_a = 1;
	if (key == KEY_D)
		mlx->move_d = 1;
	return (0);
}

int key_release(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->move_w = 0;
	if (key == KEY_S)
		mlx->move_s = 0;
	if (key == KEY_LEFT)
		mlx->move_rl = 0;
	if (key == KEY_RIGHT)
		mlx->move_rr = 0;
	if (key == KEY_A)
		mlx->move_a = 0;
	if (key == KEY_D)
		mlx->move_d = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;
	check_args(argc, argv);
	init_values(&mlx);
	get_info(argv[1], &mlx);
	init_mlx(&mlx);
	textures(&mlx);
	mlx_loop_hook(mlx.mlx, ft_raycasting , &mlx);
	mlx_hook(mlx.mlx_window, KEY_PRESS, (1L<<0), key_pressed, (void*)&mlx);
	mlx_hook(mlx.mlx_window, KEY_RELEASE, (1L<<1), key_release, (void*)&mlx);
	mlx_loop(mlx.mlx);
	return(0);
}