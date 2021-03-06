/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:54:56 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/23 09:21:28 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player2(char *buf, t_mlx *mlx, int *x, int y)
{
	if (*buf == 'E')
	{
		mlx->player.dirX = 1;
		mlx->player.dirY = 0;
		mlx->player.planoX = 0;
		mlx->player.planoY = 0.66;
	}
	mlx->map[y][*x] = 0;
	if (mlx->player.posY != 0 && mlx->player.posX != 0)
		error_exit("Mapa Invalido.");
	mlx->player.posY = (double)y + 0.5;
	mlx->player.posX = (double)*x + 0.5;
}

void	init_player(char *buf, t_mlx *mlx, int *x, int y)
{
	if (*buf == 'N')
	{
		mlx->player.dirX = 0;
		mlx->player.dirY = -1;
		mlx->player.planoX = 0.66;
		mlx->player.planoY = 0;
	}
	else if (*buf == 'S')
	{
		mlx->player.dirX = 0;
		mlx->player.dirY = 1;
		mlx->player.planoX = -0.66;
		mlx->player.planoY = 0;
	}
	else if (*buf == 'W')
	{
		mlx->player.dirX = -1;
		mlx->player.dirY = 0;
		mlx->player.planoX = 0;
		mlx->player.planoY = -0.66;
	}
	init_player2(buf, mlx, x, y);
}
