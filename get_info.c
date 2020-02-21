/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:30:34 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/21 18:51:23 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color_f(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	while(line[i] == 'F' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->floor.r = mlx->floor.r * 10 + line[i] - '0';
		i++;
	}
	while(line[i] == ',' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->floor.g = mlx->floor.g * 10 + line[i] - '0';
		i++;
	}
	while(line[i] == ',' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->floor.b = mlx->floor.b * 10 + line[i] - '0';
		i++;
	}
}
void	get_color_s(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	while(line[i] == 'C' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->sky.r = mlx->sky.r * 10 + line[i] - '0';
		i++;
	}
	while(line[i] == ',' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->sky.g = mlx->sky.g * 10 + line[i] - '0';
		i++;
	}
	while(line[i] == ',' || line[i] == ' ')
		i++;
	while(ft_isdigit(line[i]))
	{
		mlx->sky.b = mlx->sky.b * 10 + line[i] - '0';
		i++;
	}
}

void	get_sprite(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'S' || line[i] == ' ')
		i++;
	else 
		error_exit("Error\nEl mapa no es valido.");
	if (ft_strchr(line, '.'))
		mlx->path_sprite = ft_strdup(ft_strchr(line, '.'));
	else
		error_exit("Error\nEl mapa no es valido.");
}

