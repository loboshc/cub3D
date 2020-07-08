/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:37:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/08 12:25:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_size_map(char *line, t_mlx *mlx)
{
	int i;
	int max_width;

	i = 0;
	max_width = 0;
	mlx->m_height++;
	while (((line[i] >= 48 && line[i] <= 50) || line[i] == ' ' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E') && line[i])
	{
		max_width++;
		i++;
	}
	if (max_width > mlx->m_width)
		mlx->m_width = max_width;
	if (line[i] != '\0')
		error_exit("El mapa no es valido.");
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
			if (buf[p] != ' ')
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
			x++;
			mlx->p++;
		}
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
	int			i;
	int			h;

	if (buf == NULL)
		buf = ft_strdup("");
	temp = ft_strjoin(buf, line);
	free(buf);
	buf = temp;
	if (lastline == 0)
	{
		i = 0;
		h = mlx->m_height;
		if ((mlx->map = (int**)ft_calloc(sizeof(int*) * h, 1)) == NULL)
			error_exit("No se ha podido reservar memeria para el mapa");
		while (i < mlx->m_height)
		{
			mlx->map[i] = (int*)ft_calloc(sizeof(int) * mlx->m_width, 1);
			i++;
		}
		fill_map(mlx, (char*)buf);
		check_error_map(mlx);
		free_and_null((void*)buf);
	}
}

void	get_info_map(char *line, t_mlx *mlx, int lastline)
{
	int i;

	get_size_map(line, mlx);
	i = 0;
	while ((mlx->m_height == 1 || lastline == 0) && line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			error_exit("El mapa debe estar cerrado por muros [1].\n");
		i++;
	}
	if (line[mlx->m_width - 1] != ' ' && line[mlx->m_width - 1] != '1')
		error_exit("El mapa debe estar cerrado por muros [1].\n");
	copy_map(line, mlx, lastline);
}
