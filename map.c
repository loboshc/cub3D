/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:37:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/07 13:12:22 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_size_map(char *line, t_mlx *mlx)
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
		error_exit("Error\nEl mapa no es valido.");
}

static	void	check_error_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->m_height)
	{
		x = 0;
		while (x < mlx->m_width)
		{
			if(mlx->map[y][x] == 4)
			{
				//esquina superior izquierda
				if (y == 0 && x == 0)
				{
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//esquina superior derecha
				else if (y == 0 && x == mlx->m_width - 1)
				{
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//esquina inferior izquierda
				else if (x == 0 && y == mlx->m_height - 1)
				{
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//esquina inferior derecha
				else if (y == mlx->m_height - 1 && x == mlx->m_width - 1)
				{
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//fila superior
				else if (y == 0 && (x != 0 && x != mlx->m_width - 1)) 
				{
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//fila lateral izquierda
				else if (x == 0 && (y != 0 && y != mlx->m_height - 1))
				{
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//fila lateral derecha
				else if (x == mlx->m_width - 1 && (y != 0 && y != mlx->m_height - 1))
				{
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//fila inferior
				else if (y == mlx->m_height - 1 && (x != 0 && x != mlx->m_width - 1))
				{
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
				//relleno
				else
				{
					if (mlx->map[y][x - 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y][x + 1] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y - 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
					if (mlx->map[y + 1][x] == 0)
						error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].");
				}
			}
			x++;
		}
		y++;
	}
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
			else if (buf[p] == '2')
			{
				mlx->sprite_num++;
				mlx->map[y][x] = 0;
			}
			else if (buf[p] == ' ')
				mlx->map[y][x] = 4;
			else if (buf[p] != ' ' && buf[p] != '\n')
				mlx->map[y][x] = buf[p] - '0';
			x++;
			p++;
		}
		y++;
	}
	if (mlx->sprite_num > 0)
	{
		//mlx->sprite_num++;
		get_info_sprites(mlx, buf);
	}
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
		check_error_map(mlx);
		free_and_null((void*)buf);
	}
}

void			get_info_map(char *line, t_mlx *mlx, int lastline)
{
	int i;

	get_size_map(line, mlx);
	i = 0;
	while ((mlx->m_height == 1 || lastline == 0) && line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			error_exit("Error\nEl mapa tiene que estar rodeado por muros [1].\n");
		i++;
	}
	copy_map(line, mlx, lastline);
}
