/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:37:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/27 16:50:03 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_size_map(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->m_height++;
	while (((line[i] >= 48 && line[i] <= 50) || line[i] == ' ' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E') && line[i])
	{
		if (mlx->m_height == 1 && line[i] == '1')
			mlx->m_width++;
		i++;
	}
	if (line[i] != '\0')
		error_exit("Error\nEl mapa no es valido.");
}

static	void	check_error_map(char *line, t_mlx *mlx, int lastline)
{
	int i;
	int count;

	i = 0;
	while ((mlx->m_height == 1 || lastline == 0) && line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
		i++;
	}
	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			count++;
		i++;
	}
	if (count != mlx->m_width)
		error_exit("Error\nEl mapa no es valido.");
	if (line[i - 1] != '1')
		error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
}

void	get_info_sprites(t_mlx *mlx, char *buf)
{
	int x;
	int y;
	int p;
	int sprite_num;

	y = 0;
	p = 0;
	sprite_num = 0;
	mlx->sprite = malloc(sizeof(t_sprite) * mlx->sprite_num);
	while (y < mlx->m_height && sprite_num < mlx->sprite_num)
	{
		x = 0;
		while (x < mlx->m_width && sprite_num < mlx->sprite_num)
		{
			if (buf[p] != ' ')
			{
				if (buf[p] == '2')
				{
					mlx->sprite[sprite_num].x = x;
					mlx->sprite[sprite_num].y = y;
					sprite_num++;
				}
				x++;
			}
			p++;
		}
		y++;
	}
}

static	void	fill_map(t_mlx *mlx, char *buf)
{
	int x;
	int y;
	int p;

	y = 0;
	p = 0;
	while (y < mlx->m_height)
	{
		x = 0;
		while (x < mlx->m_width)
		{
			if (ft_isalpha(buf[p]))
				init_player(&buf[p], mlx, &x, y);
			else if (buf[p] != ' ')
			{
				if (buf[p] == '2')
					mlx->sprite_num++;
				mlx->map[y][x] = buf[p] - '0';
				x++;
			}
			p++;
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

static	void	copy_map(char *line, t_mlx *mlx, int lastline)
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
			error_exit("Error\nNo se ha podido reservar memeria para el mapa");
		while (i < mlx->m_height)
		{
			mlx->map[i] = (int*)ft_calloc(sizeof(int) * mlx->m_width, 1);
			i++;
		}
		fill_map(mlx, (char*)buf);
		free_and_null((void*)buf);
	}
}

void			get_info_map(char *line, t_mlx *mlx, int lastline)
{
	get_size_map(line, mlx);
	check_error_map(line, mlx, lastline);
	copy_map(line, mlx, lastline);
}
