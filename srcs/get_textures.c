/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:12:27 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/21 12:16:39 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_north(t_mlx *mlx, char *line)
{
	int i;
	int fd;

	i = 0;
	if (mlx->path_north != NULL)
		error_exit("Se ha duplicado la textura norte.");
	while (line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
			i++;
		else if (line[i] == '.')
			break ;
		else
			error_exit("El formato de la textura norte es erronea.");
	}
	if (ft_strchr(line, '.'))
		mlx->path_north = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("La textura debe estar en la carpeta del juego.");
	if ((fd = open(mlx->path_north, O_RDONLY)) < 0)
		error_exit("La textura norte no se puede encontrar.");
	else
		close(fd);
}

void	get_texture_south(t_mlx *mlx, char *line)
{
	int i;
	int fd;

	i = 0;
	if (mlx->path_south != NULL)
		error_exit("Se ha duplicado la textura sur.");
	while (line[i] != '\n')
	{
		if (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
			i++;
		else if (line[i] == '.')
			break ;
		else
			error_exit("El formato de la textura sur es erronea.");
	}
	if (ft_strchr(line, '.'))
		mlx->path_south = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("La textura debe estar en la carpeta del juego.");
	if ((fd = open(mlx->path_south, O_RDONLY)) < 0)
		error_exit("La textura sur no se puede encontrar.");
	else
		close(fd);
}

void	get_texture_west(t_mlx *mlx, char *line)
{
	int i;
	int fd;

	i = 0;
	if (mlx->path_west != NULL)
		error_exit("Se ha duplicado la textura oeste.");
	while (line[i] != '\n')
	{
		if (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
			i++;
		else if (line[i] == '.')
			break ;
		else
			error_exit("El formato de la textura oeste es erronea.");
	}
	if (ft_strchr(line, '.'))
		mlx->path_west = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("La textura debe estar en la carpeta del juego.");
	if ((fd = open(mlx->path_west, O_RDONLY)) < 0)
		error_exit("La textura oeste no se puede encontrar.");
	else
		close(fd);
}

void	get_texture_east(t_mlx *mlx, char *line)
{
	int i;
	int fd;

	i = 0;
	if (mlx->path_east != NULL)
		error_exit("Se ha duplicado la textura este.");
	while (line[i] != '\n')
	{
		if (line[i] == 'E' || line[i] == 'A' || line[i] == ' ')
			i++;
		else if (line[i] == '.')
			break ;
		else
			error_exit("El formato de la textura este es erronea.");
	}
	if (ft_strchr(line, '.'))
		mlx->path_east = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("La textura debe estar en la carpeta del juego.");
	if ((fd = open(mlx->path_east, O_RDONLY)) < 0)
		error_exit("La textura este no se puede encontrar.");
	else
		close(fd);
}

void	get_textures(t_mlx *mlx, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		get_texture_north(mlx, line);
	else if (line[0] == 'S' && line[1] == 'O')
		get_texture_south(mlx, line);
	else if (line[0] == 'W' && line[1] == 'E')
		get_texture_west(mlx, line);
	else if (line[0] == 'E' && line[1] == 'A')
		get_texture_east(mlx, line);
	else if (line[0] == 'S' && line[1] != 'O')
		get_sprite(mlx, line);
}
