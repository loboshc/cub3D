/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:46:32 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/20 20:53:12 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_dda(t_mlx *mlx)
{
	if (mlx->rayDirX < 0)
	{
		mlx->stepX = -1;
		mlx->sideDistX = (mlx->player.posX - mlx->mapX) * mlx->deltaDistX;
	}
	else
	{
		mlx->stepX = 1;
		mlx->sideDistX = (mlx->mapX + 1.0 - mlx->player.posX) * mlx->deltaDistX;
	}
	if (mlx->rayDirY < 0)
	{
		mlx->stepY = -1;
		mlx->sideDistY = (mlx->player.posY - mlx->mapY) * mlx->deltaDistY;
	}
	else
	{
		mlx->stepY = 1;
		mlx->sideDistY = (mlx->mapY + 1.0 - mlx->player.posY) * mlx->deltaDistY;
	}
}

void	perform_dda(t_mlx *mlx)
{
	mlx->hit = 0;
	while (mlx->hit == 0)
	{
		if (mlx->sideDistX < mlx->sideDistY)
		{
			mlx->sideDistX += mlx->deltaDistX;
			mlx->mapX += mlx->stepX;
			mlx->side = 0;
		}
		else
		{
			mlx->sideDistY += mlx->deltaDistY;
			mlx->mapY += mlx->stepY;
			mlx->side = 1;
		}
		if (mlx->map[mlx->mapY][mlx->mapX] > 0)
			mlx->hit = 1;
	}
	if (mlx->side == 0)
		mlx->perpWallDist = (mlx->mapX - mlx->player.posX +
		(1 - mlx->stepX) / 2) / mlx->rayDirX;
	else
		mlx->perpWallDist = (mlx->mapY - mlx->player.posY +
		(1 - mlx->stepY) / 2) / mlx->rayDirY;
	mlx->lineHeight = (int)(mlx->s_height / mlx->perpWallDist);
}

void	calculate_pixel(t_mlx *mlx)
{
	mlx->drawStar = (mlx->lineHeight * -1) / 2 + mlx->s_height / 2;
	if (mlx->drawStar < 0)
		mlx->drawStar = 0;
	mlx->drawEnd = mlx->lineHeight / 2 + mlx->s_height / 2;
	if (mlx->drawEnd >= mlx->s_height)
		mlx->drawEnd = mlx->s_height - 1;
}

void	draw_all(t_mlx *mlx, int x)
{
	calculate_pixel(mlx);
	while (mlx->drawStar < mlx->drawEnd)
	{
		if (mlx->side == 0)
		{
			if (mlx->stepX < 0)
				mlx->addr_img[4 * (x + mlx->drawStar * mlx->s_width) +
				1] = (char)100;
			else
				mlx->addr_img[4 * (x + mlx->drawStar * mlx->s_width) +
				1] = (char)255;
		}
		else
		{
			if (mlx->stepY > 0)
				mlx->addr_img[4 * (x + mlx->drawStar * mlx->s_width) +
				2] = (char)255;
			else
				mlx->addr_img[4 * (x + mlx->drawStar *
				mlx->s_width)] = (char)255;
		}
		mlx->drawStar++;
	}
}

int		ft_raycasting(t_mlx *mlx)
{
	int x;

	x = 0;
	if (mlx->move_w || mlx->move_s || mlx->move_rr || mlx->move_rl
		|| mlx->move_a || mlx->move_d)
		move_handler(mlx);
	mlx->img = mlx_new_image(mlx->mlx, mlx->s_width, mlx->s_height);
	mlx->addr_img = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->size, &mlx->e);
	while (x < mlx->s_width)
	{
		mlx->cameraX = 2 * x / (double)mlx->s_width - 1;
		mlx->rayDirX = mlx->player.dirX + mlx->player.planoX * mlx->cameraX;
		mlx->rayDirY = mlx->player.dirY + mlx->player.planoY * mlx->cameraX;
		mlx->mapX = (int)mlx->player.posX;
		mlx->mapY = (int)mlx->player.posY;
		mlx->deltaDistX = (mlx->rayDirY == 0) ? 0 : ((mlx->rayDirX == 0) ? 1 : fabs(1 / mlx->rayDirX));
		mlx->deltaDistY = (mlx->rayDirX == 0) ? 0 : ((mlx->rayDirY == 0) ? 1 : fabs(1 / mlx->rayDirY));
		calculate_dda(mlx);
		perform_dda(mlx);
		draw_all(mlx, x);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
	return (0);
}
