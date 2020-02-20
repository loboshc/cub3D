/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:08:58 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/20 20:53:09 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_rotate(t_mlx *mlx)
{	
	float rotate;
	double old_dirX;
	double	old_planeX;
	
	if (mlx->move_rr)
		rotate = ROT_SPEED;
	else 
		rotate = -ROT_SPEED;
	old_dirX = mlx->player.dirX;
	mlx->player.dirX = mlx->player.dirX * cos(rotate) - mlx->player.dirY * sin(rotate);
	mlx->player.dirY = old_dirX * sin(rotate) + mlx->player.dirY * cos(rotate);
	old_planeX = mlx->player.planoX;
	mlx->player.planoX = mlx->player.planoX * cos(rotate) - mlx->player.planoY * sin(rotate);
	mlx->player.planoY = old_planeX * sin(rotate) + mlx->player.planoY * cos(rotate);
	
}

void	move_sides(t_mlx *mlx)
{
	if (mlx->move_a)
	{
		if (mlx->map[(int)(mlx->player.posY - mlx->player.planoY * 0.5)][(int)mlx->player.posX] == 0)
			mlx->player.posY -= mlx->player.planoY * MV_SPEED;
		if (mlx->map[(int)mlx->player.posY][(int)(mlx->player.posX - mlx->player.planoX * 0.5)] == 0)
			mlx->player.posX -= mlx->player.planoX * MV_SPEED;
	}
	if (mlx->move_d)
	{
		if (mlx->map[(int)(mlx->player.posY + mlx->player.planoY * 0.5)][(int)mlx->player.posX] == 0)
			mlx->player.posY += mlx->player.planoY * MV_SPEED;
		if (mlx->map[(int)mlx->player.posY][(int)(mlx->player.posX + mlx->player.planoX * 0.5)] == 0)
			mlx->player.posX += mlx->player.planoX * MV_SPEED;
	}
}

void	move_handler(t_mlx *mlx)
{
	if (mlx->move_w)
	{
		if (mlx->map[(int)(mlx->player.posY + mlx->player.dirY * 0.5)][(int)mlx->player.posX] == 0)
			mlx->player.posY += mlx->player.dirY * MV_SPEED;
		if (mlx->map[(int)mlx->player.posY][(int)(mlx->player.posX + mlx->player.dirX * 0.5)] == 0)
			mlx->player.posX += mlx->player.dirX * MV_SPEED;
	}
	if (mlx->move_s)
	{
		if (mlx->map[(int)(mlx->player.posY - mlx->player.dirY * 0.5)][(int)mlx->player.posX] == 0)
			mlx->player.posY -= mlx->player.dirY * MV_SPEED;
		if (mlx->map[(int)mlx->player.posY][(int)(mlx->player.posX - mlx->player.dirX * 0.5)] == 0)
			mlx->player.posX -= mlx->player.dirX * MV_SPEED;
	}
	if (mlx->move_a || mlx->move_d)
		move_sides(mlx);
	if (mlx->move_rl || mlx->move_rr)
		move_rotate(mlx);
}