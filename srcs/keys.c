/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:32:11 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/21 13:07:08 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_mlx *mlx)
{
	free(mlx->path_west);
	free(mlx->path_east);
	free(mlx->path_north);
	free(mlx->path_south);
	mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit_game(mlx);
	if (key == KEY_W)
		mlx->move_w = 1;
	if (key == KEY_S)
		mlx->move_s = 1;
	if (key == KEY_LEFT)
		mlx->move_rl = 1;
	if (key == KEY_RIGHT)
		mlx->move_rr = 1;
	if (key == KEY_A)
		mlx->move_a = 1;
	if (key == KEY_D)
		mlx->move_d = 1;
	if (key == 257)
		mlx->move_speed = MOVE_SPEED + 0.05;
	if (key == 3)
	{
		if (mlx->f == 0)
			mlx->f = 1;
		else if (mlx->f == 1)
			mlx->f = 0;
	}
	return (0);
}

int	key_release(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->move_w = 0;
	if (key == KEY_S)
		mlx->move_s = 0;
	if (key == KEY_LEFT)
		mlx->move_rl = 0;
	if (key == KEY_RIGHT)
		mlx->move_rr = 0;
	if (key == KEY_A)
		mlx->move_a = 0;
	if (key == KEY_D)
		mlx->move_d = 0;
	if (key == 257)
		mlx->move_speed = MOVE_SPEED;
	return (0);
}
