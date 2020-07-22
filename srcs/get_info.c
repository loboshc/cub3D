/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:30:34 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/22 11:43:06 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color_f(t_mlx *mlx, char *line)
{
	if (mlx->floor.r != 0 || mlx->floor.g != 0 || mlx->floor.b != 0 ||
		(ft_strchr(line, '-') != NULL))
		error_exit("Mapa Invalido.");
	while (line[mlx->i] == 'F' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->floor.r = mlx->floor.r * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	while (line[mlx->i] == ',' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->floor.g = mlx->floor.g * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	while (line[mlx->i] == ',' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->floor.b = mlx->floor.b * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	ft_isdigit(line[mlx->i]) || line[mlx->i] == '\0' ? 0 : error_exit("Suelo.");
}

void	get_color_s(t_mlx *mlx, char *line)
{
	if (mlx->sky.r != 0 || mlx->sky.g != 0 || mlx->sky.b != 0 ||
		(ft_strchr(line, '-') != NULL))
		error_exit("Mapa Invalido.");
	while (line[mlx->i] == 'C' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->sky.r = mlx->sky.r * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	while (line[mlx->i] == ',' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->sky.g = mlx->sky.g * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	while (line[mlx->i] == ',' || line[mlx->i] == ' ')
		mlx->i++;
	while (ft_isdigit(line[mlx->i]))
	{
		mlx->sky.b = mlx->sky.b * 10 + line[mlx->i] - '0';
		mlx->i++;
	}
	ft_isdigit(line[mlx->i]) || line[mlx->i] == '\0' ? 0 : error_exit("Cielo.");
}

void	get_sprite(t_mlx *mlx, char *line)
{
	int i;
	int fd;

	i = 0;
	if (mlx->path_sprite != NULL)
		error_exit("Se ha duplicado la textura sprite.");
	while (line[i] != '\n')
	{
		if (line[i] == 'S' || line[i] == ' ')
			i++;
		else if (line[i] == '.')
			break ;
		else
			error_exit("El formato de la textura sprite es erronea.");
	}
	if (ft_strchr(line, '.'))
		mlx->path_sprite = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("El mapa no es valido.");
	if ((fd = open(mlx->path_sprite, O_RDONLY)) < 0)
		error_exit("La textura sprite no se puede encontrar.");
	else
		close(fd);
}
