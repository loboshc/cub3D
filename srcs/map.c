/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:37:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/20 10:35:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_size_map(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->m_height++;
	while (((line[i] >= 48 && line[i] <= 50) || line[i] == ' ' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E') && line[i])
	{
		mlx->max_width[mlx->row]++;
		i++;
	}
	if (mlx->max_width[mlx->row] > mlx->m_width)
		mlx->m_width = mlx->max_width[mlx->row];
	if (line[i] != '\0')
		error_exit("El mapa no es valido.");
	mlx->read_map = 1;
}

void	get_info_sprites(t_mlx *mlx, char *buf)
{
	int y;
	int p;

	y = 0;
	p = 0;
	mlx->sp_num = 0;
	mlx->sprite = malloc(sizeof(t_sprite) * (mlx->sprite_num));
	while (y < mlx->m_height && mlx->sp_num < mlx->sprite_num)
	{
		mlx->x = 0;
		while (mlx->x < mlx->max_width[y] && mlx->sp_num < mlx->sprite_num)
		{
			if (buf[p] == '2')
			{
				mlx->sprite[mlx->sp_num].x = mlx->x;
				mlx->sprite[mlx->sp_num].y = y;
				mlx->sp_num++;
			}
			p++;
			mlx->x++;
			if (buf[p] == '\n')
				mlx->x--;
		}
		y++;
	}
}

void	fill_map(t_mlx *mlx, char *buf)
{
	while (mlx->m_y < mlx->m_height)
	{
		mlx->m_x = 0;
		while (mlx->m_x < mlx->m_width)
		{
			if (ft_isalpha(buf[mlx->p]))
				init_player(&buf[mlx->p], mlx, &mlx->m_x, mlx->m_y);
			else if (buf[mlx->p] == '2')
				sprite_fill_map(mlx, mlx->m_y, mlx->m_x);
			else if (buf[mlx->p] == ' ')
				mlx->map[mlx->m_y][mlx->m_x] = 4;
			else if (buf[mlx->p] != ' ' && buf[mlx->p] != '\n')
				mlx->map[mlx->m_y][mlx->m_x] = buf[mlx->p] - '0';
			else if (buf[mlx->p] == '\n' && mlx->m_x < mlx->m_width)
				mlx->map[mlx->m_y][mlx->m_x] = 4;
			mlx->m_x++;
			if (buf[mlx->p] != '\n')
				mlx->p++;
		}
		mlx->p++;
		mlx->m_y++;
	}
	if (mlx->sprite_num > 0)
		get_info_sprites(mlx, buf);
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
			if (line[mlx->max_width[mlx->row] - 1] != ' ' &&
			line[mlx->max_width[mlx->row] - 1] != '1')
				error_exit("El mapa debe estar cerrado por muros [1].\n");
		copy_map(line, mlx, lastline);
		mlx->row++;
	}
}
