/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:05:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/20 10:33:24 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *s)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

void	free_and_null(void *obj)
{
	free(obj);
	obj = NULL;
}

void	put_pixel(t_mlx *mlx, int color, int x)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = x * (mlx->bit / 8) + mlx->drawStar * mlx->size;
	while (i < (mlx->bit / 8))
	{
		mlx->addr_img[j + i] = color;
		color >>= 8;
		i++;
	}
}

void	put_pixel_sprite(t_mlx *mlx, int color, int x, int y)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = x * (mlx->bit / 8) + y * mlx->size;
	while (i < (mlx->bit / 8))
	{
		mlx->addr_img[j + i] = color;
		color >>= 8;
		i++;
	}
}

void	sprite_fill_map(t_mlx *mlx, int y, int x)
{
	mlx->sprite_num++;
	mlx->map[y][x] = 2;
}
