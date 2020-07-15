/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:29:22 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/15 12:02:32 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	while (line[i] == 'R' || line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		mlx->s_width = mlx->s_width * 10 + line[i] - '0';
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		mlx->s_height = mlx->s_height * 10 + line[i] - '0';
		i++;
	}
}

void	check_file(t_mlx *mlx, char *line)
{
	if (mlx->read_map == 1)
	{
		if (mlx->s_width == 0 && mlx->s_height == 0)
			error_exit("Mapa invalido.");
		if (mlx->path_north == NULL || mlx->path_south == NULL ||
			mlx->path_west == NULL || mlx->path_east == NULL ||
			mlx->path_sprite == NULL)
			error_exit("Mapa invalido.");
		if (mlx->floor.r == 0 && mlx->floor.g == 0 &&
			mlx->floor.b == 0)
			error_exit("Mapa invalido.");
		if (mlx->sky.r == 0 && mlx->sky.g == 0 &&
			mlx->sky.b == 0)
			error_exit("Mapa invalido.");
	}
}

void	get_info_line(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
		get_resolution(line, mlx);
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E')
		get_textures(mlx, &line[i]);
	else if (line[i] == 'F')
		get_color_f(mlx, line);
	else if (line[i] == 'C')
		get_color_s(mlx, line);
	else if (line[i] == '1' || *line == '\0')
		get_info_map(line, mlx, mlx->lastline);
	else if (ft_isdigit(*line))
		error_exit("El mapa tiene que estar rodeado por muros [1].");
}

void	create_map(t_mlx *mlx)
{
	int i;
	int h;

	i = 0;
	h = mlx->m_height;
	if ((mlx->map = (int**)ft_calloc(sizeof(int*) * h, 1)) == NULL)
		error_exit("No se ha podido reservar memeria para el mapa");
	while (i < mlx->m_height)
	{
		mlx->map[i] = (int*)ft_calloc(sizeof(int) * mlx->m_width, 1);
		i++;
	}
}

void	get_info(char *argv, t_mlx *mlx)
{
	int		fd;
	char	*line; 

	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit("El mapa no existe o no se encuentra");
	while ((mlx->lastline = get_next_line(fd, &line)) > EOF)
	{
		check_file(mlx, line);
		get_info_line(mlx, line);
		free_and_null(line);
		if (!mlx->lastline)
			break ;
	}
	close(fd);
}
