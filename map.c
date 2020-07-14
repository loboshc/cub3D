/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:37:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/14 13:21:08 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_size_map(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->max_width = 0;
	mlx->m_height++;
	while (((line[i] >= 48 && line[i] <= 50) || line[i] == ' ' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E') && line[i])
	{
		mlx->max_width++;
		i++;
	}
	if (mlx->max_width > mlx->m_width)
		mlx->m_width = mlx->max_width;
	if (line[i] != '\0')
		error_exit("El mapa no es valido.");
	mlx->read_map = 1;
}

void	get_info_sprites(t_mlx *mlx, char *buf)
{
	int y;
	int p;
	int sprite_num;

	y = 0;
	p = 0;
	sprite_num = 0;
	mlx->sprite = malloc(sizeof(t_sprite) * (mlx->sprite_num));
	while (y < mlx->m_height && sprite_num < mlx->sprite_num)
	{
		mlx->x = 0;
		while (mlx->x < mlx->m_width && sprite_num < mlx->sprite_num)
		{
			if (buf[p] == '2')
			{
				mlx->sprite[sprite_num].x = mlx->x;
				mlx->sprite[sprite_num].y = y;
				sprite_num++;
			}
			p++;
			mlx->x++;
		}
		y++;
	}
}

void	fill_map(t_mlx *mlx, char *buf)
{
	int x;
	int y;

	y = 0;
	mlx->p = 0;
	while (y < mlx->m_height)
	{
		x = 0;
		while (x < mlx->m_width)
		{
			if (ft_isalpha(buf[mlx->p]))
				init_player(&buf[mlx->p], mlx, &x, y);
			else if (buf[mlx->p] == '2')
				sprite_fill_map(mlx, y, x);
			else if (buf[mlx->p] == ' ')
				mlx->map[y][x] = 4;
			else if (buf[mlx->p] != ' ' && buf[mlx->p] != '\n')
				mlx->map[y][x] = buf[mlx->p] - '0';
			else if (buf[mlx->p] == '\n' && x < mlx->m_width)
				mlx->map[y][x] = 4;
			x++;
			if (buf[mlx->p] != '\n')
				mlx->p++;
		}
		mlx->p++;
		y++;
	}
	if (mlx->sprite_num > 0)
		get_info_sprites(mlx, buf);
	//pintar el mapa en la consola BORRAR
	y = 0;
	while (y < mlx->m_height)
	{
		x = 0;
		while (x < mlx->m_width)
		{
			printf("%d", mlx->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	copy_map(char *line, t_mlx *mlx, int lastline)
{
	static char	*buf;
	char		*temp;
	char		*temp2;

	if (buf == NULL)
		buf = ft_strdup("");
	temp = ft_strjoin(buf, line);
	temp2 = ft_strjoin(temp, "\n");
	free(temp);
	free(buf);
	buf = temp2;
	if (lastline == 0)
	{
		create_map(mlx);
		fill_map(mlx, (char*)buf);
		check_error_map(mlx);
		free_and_null((void*)buf);
	}
}

void	get_info_map(char *line, t_mlx *mlx, int lastline)
{
	int i;

	if (*line != '\0' || lastline == 0)
	{
		get_size_map(line, mlx);
		i = 0;
		while ((mlx->m_height == 1 || lastline == 0) && line[i])
		{
			if (line[i] != '1' && line[i] != ' ')
				error_exit("El mapa debe estar cerrado por muros [1].\n");
			i++;
		}
		if (*line != '\0')
			if (line[mlx->max_width - 1] != ' ' &&
			line[mlx->max_width - 1] != '1')
				error_exit("El mapa debe estar cerrado por muros [1].\n");
		copy_map(line, mlx, lastline);
	}
}
