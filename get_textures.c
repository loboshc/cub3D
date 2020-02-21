/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:12:27 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/21 18:51:18 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_north(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
		i++;
	else 
		error_exit("Error\nEl mapa no es valido.");
	if (ft_strchr(line, '.'))
		mlx->path_north = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("Error\nEl mapa no es valido.");
}

void	get_texture_south(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
		i++;
	else 
		error_exit("Error\nEl mapa no es valido.");
	if (ft_strchr(line, '.'))
		mlx->path_south = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("Error\nEl mapa no es valido.");
}

void	get_texture_west(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
		i++;
	else 
		error_exit("Error\nEl mapa no es valido.");
	if (ft_strchr(line, '.'))
		mlx->path_west = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("Error\nEl mapa no es valido.");
}

void	get_texture_east(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'E' || line[i] == 'A' || line[i] == ' ')
		i++;
	else 
		error_exit("Error\nEl mapa no es valido.");
	if (ft_strchr(line, '.'))
		mlx->path_east = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("Error\nEl mapa no es valido.");
}

void	get_textures(t_mlx *mlx, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		get_texture_north(mlx, line);
	if (line[0] == 'S' && line[1] == 'O')
		get_texture_south(mlx, line);
	if (line[0] == 'W' && line[1] == 'E')
		get_texture_west(mlx, line);
	if (line[0] == 'E' && line[1] == 'A')
		get_texture_east(mlx, line);
	if (*line == 'S')
		get_sprite(mlx, line);
}