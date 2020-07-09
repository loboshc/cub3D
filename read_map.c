/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:29:22 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/09 13:40:39 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->s_width = 0;
	mlx->s_height = 0;
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

void	get_info(char *argv, t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		lastline;

	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit("El mapa no existe o no se encuentra");
	while ((lastline = get_next_line(fd, &line)) > EOF)
	{
		if (*line == 'R')
			get_resolution(line, mlx);
		else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
			get_textures(mlx, line);
		else if (*line == 'F')
			get_color_f(mlx, line);
		else if (*line == 'C')
			get_color_s(mlx, line);
		else if (*line == '1' || *line == ' ' || *line == '\0')
			get_info_map(line, mlx, lastline);
		else if (ft_isdigit(*line))
			error_exit("El mapa tiene que estar rodeado por muros [1].");
		free_and_null((void*)line);
		if (!lastline)
			break ;
	}
	close(fd);
}
