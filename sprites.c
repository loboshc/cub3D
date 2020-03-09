/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:59:54 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/03/09 19:31:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	real_sort_sprites(t_mlx *mlx, double *distance, int *sprite_order)
{
	double	disttemp;
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < mlx->sprite_num)
	{
		j = 0;
		while (j < mlx->sprite_num)
		{
			if (distance[i] > distance[j])
			{
				disttemp = distance[i];
				distance[i] = distance[j];
				distance[j] = disttemp;
				temp = sprite_order[i];
				sprite_order[i] = sprite_order[j];
				sprite_order[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_mlx *mlx, int *sprite_order)
{
	double	distance[mlx->sprite_num];
	int		i;

	i = -1;
	while (++i < mlx->sprite_num)
	{
		sprite_order[i] = i;
		distance[i] = ((mlx->player.posX - mlx->sprite[i].x) *
		(mlx->player.posX - mlx->sprite[i].x) + (mlx->player.posY -
		mlx->sprite[i].y) * (mlx->player.posY - mlx->sprite[i].y));
	}
	real_sort_sprites(mlx, distance, sprite_order);
}

void	calcule_sprite_height(t_mlx *mlx)
{
	mlx->sp_calc.height = abs((int)(mlx->s_height /
	(mlx->sp_calc.transY)));
	mlx->sp_calc.drawstarty = -mlx->sp_calc.height /
	2 + mlx->s_height / 2;
	if (mlx->sp_calc.drawstarty < 0)
		mlx->sp_calc.drawstarty = 0;
	mlx->sp_calc.drawendy = mlx->sp_calc.height / 2 + mlx->s_height / 2;
	if (mlx->sp_calc.drawendy >= mlx->s_height)
		mlx->sp_calc.drawendy = mlx->s_height - 1;
}

void	calcule_sprite_width(t_mlx *mlx)
{
	mlx->sp_calc.width = abs((int)(mlx->s_height /
	(mlx->sp_calc.transY)));
	mlx->sp_calc.drawstartx = (mlx->sp_calc.width * -1)
	/ 2 + mlx->sp_calc.screen_x;
	if (mlx->sp_calc.drawstartx < 0)
		mlx->sp_calc.drawstartx = 0;
	mlx->sp_calc.drawendx = mlx->sp_calc.width /
	2 + mlx->sp_calc.screen_x;
	if (mlx->sp_calc.drawendx >= mlx->s_width)
		mlx->sp_calc.drawendx = mlx->s_width - 1;
}

void	calculations_sprites(t_mlx *mlx, int y, int stripe)
{
	mlx->sp_calc.d = (y) * 256 - mlx->s_height * 128 +
	mlx->sp_calc.height * 128;
	mlx->sp_calc.textY = ((mlx->sp_calc.d * mlx->textsp.height) /
	mlx->sp_calc.height) / 256;
	mlx->sp_calc.color = mlx->textsp.addr[mlx->textsp.size / 4 *
	mlx->sp_calc.textY + mlx->sp_calc.textX];
}
