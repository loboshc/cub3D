/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:28:44 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/20 11:27:47 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_all_sprites(t_mlx *mlx)
{
	int	y;
	int	stripe;
	int width;

	width = mlx->sp_calc.width;
	stripe = mlx->sp_calc.drawstartx;
	while (stripe < mlx->sp_calc.drawendx)
	{
		mlx->sp_calc.textX = (int)(256 * (stripe - (-width / 2 +
		mlx->sp_calc.screen_x)) * mlx->textsp.width / width) / 256;
		if (mlx->sp_calc.transY > 0 && stripe > 0 && stripe < mlx->s_width &&
			mlx->sp_calc.transY <= mlx->zbuffer[stripe])
		{
			y = mlx->sp_calc.drawstarty;
			while (y < mlx->sp_calc.drawendy)
			{
				calculations_sprites(mlx, y);
				if ((mlx->sp_calc.color & 0x00FFFFFF) != 0)
					put_pixel_sprite(mlx, mlx->sp_calc.color, stripe, y);
				y++;
			}
		}
		stripe++;
	}
}

void	draw_sprites(t_mlx *mlx)
{
	int		i;
	int		sprite_order[mlx->sprite_num];

	sort_sprites(mlx, sprite_order);
	i = 0;
	while (i < mlx->sprite_num)
	{
		mlx->sp_calc.x = (mlx->sprite[sprite_order[i]].x + 0.5)
		- mlx->player.posX;
		mlx->sp_calc.y = (mlx->sprite[sprite_order[i]].y + 0.5)
		- mlx->player.posY;
		mlx->sp_calc.invdet = 1.0 / (mlx->player.planoX * mlx->player.dirY -
		mlx->player.dirX * mlx->player.planoY);
		mlx->sp_calc.transX = mlx->sp_calc.invdet * (mlx->player.dirY *
		mlx->sp_calc.x - mlx->player.dirX * mlx->sp_calc.y);
		mlx->sp_calc.transY = mlx->sp_calc.invdet * (-mlx->player.planoY *
		mlx->sp_calc.x + mlx->player.planoX * mlx->sp_calc.y);
		mlx->sp_calc.screen_x = ((mlx->s_width / 2) *
		(1 + mlx->sp_calc.transX / mlx->sp_calc.transY));
		calcule_sprite_width(mlx);
		calcule_sprite_height(mlx);
		draw_all_sprites(mlx);
		i++;
	}
}
