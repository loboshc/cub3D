/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:59:54 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/03/04 21:48:51 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void sort_sprites(t_mlx *mlx, int sprite_order[])
{
	double	distance[mlx->sprite_num];
	int temp;
	int disttemp;
	int i;
	int j;

	i = -1;
	while (++i < mlx->sprite_num)
	{
		sprite_order[i] = i;
		distance[i] = ((mlx->player.posX - mlx->sprite[i].x) * (mlx->player.posX -
		mlx->sprite[i].x) + (mlx->player.posY- mlx->sprite[i].y) * (mlx->player.posY -
		mlx->sprite[i].y));
	}
	i = -1;
	while(++i < mlx->sprite_num)
	{
		j = 0;
		while(++j < mlx->sprite_num)
		{
			if (distance[i] < distance[j])
			{
				disttemp = distance[i];
				distance[i] = distance[j];
				distance[j] = disttemp;
				temp = sprite_order[i];
				sprite_order[i] = sprite_order[j];
				sprite_order[j] = temp;
			}
		}
	}
}

static	void	calcule_sprite_height(t_mlx *mlx)
{
	
	mlx->sprite_calc.height = abs((int)(mlx->s_height/ (mlx->sprite_calc.transY)));
	mlx->sprite_calc.drawstarty = -mlx->sprite_calc.height / 2 + mlx->s_height / 2;
	if (mlx->sprite_calc.drawstarty < 0)
		mlx->sprite_calc.drawstarty = 0;
	mlx->sprite_calc.drawendy = mlx->sprite_calc.height / 2 + mlx->s_height / 2;
	if (mlx->sprite_calc.drawendy >= mlx->s_height)
		mlx->sprite_calc.drawendy = mlx->s_height - 1;
}

static	void	calcule_sprite_width(t_mlx *mlx)
{
	
	mlx->sprite_calc.width = abs((int)(mlx->s_height/ (mlx->sprite_calc.transY)));
	mlx->sprite_calc.drawstartx = (mlx->sprite_calc.width * -1) / 2 + mlx->sprite_calc.screen_x;
	if (mlx->sprite_calc.drawstartx < 0)
		mlx->sprite_calc.drawstartx = 0;
	mlx->sprite_calc.drawendx = mlx->sprite_calc.width  / 2 + mlx->sprite_calc.screen_x;
	if (mlx->sprite_calc.drawendx >= mlx->s_width)
		mlx->sprite_calc.drawendx = mlx->s_width - 1;
}

static	void	draw_all_sprites(t_mlx *mlx)
{

	int y;
	int stripe;

	stripe = mlx->sprite_calc.drawstartx;
	while(stripe < mlx->sprite_calc.drawendx)
	{
		mlx->sprite_calc.textX = (int)(256 * (stripe - (-mlx->sprite_calc.width / 2 + mlx->sprite_calc.screen_x)) * mlx->textsp.width / mlx->sprite_calc.width) / 256;
		if (mlx->sprite_calc.transY > 0 && stripe > 0 && stripe < mlx->s_width && 
			mlx->sprite_calc.transY < mlx->zbuffer[stripe])
		{
			y = mlx->sprite_calc.drawstarty;
			while (y < mlx->sprite_calc.drawendy)
			{
				mlx->sprite_calc.d = (y) * 256 - mlx->s_height * 128 + mlx->sprite_calc.height * 128;			
				mlx->sprite_calc.textY = ((mlx->sprite_calc.d * mlx->textsp.height) /
				mlx->sprite_calc.height) / 256;
				mlx->sprite_calc.color = mlx->textsp.addr[mlx->textsp.size / 4 * mlx->sprite_calc.textY + mlx->sprite_calc.textX];
				if ((mlx->sprite_calc.color & 0x00FFFFFF) != 0)
					put_pixel_sprite(mlx,mlx->sprite_calc.color, stripe, y);
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
		mlx->sprite_calc.x = (mlx->sprite[sprite_order[i]].x + 0.5) - mlx->player.posX;
		mlx->sprite_calc.y = (mlx->sprite[sprite_order[i]].y + 0.5) - mlx->player.posY;
		mlx->sprite_calc.invdet = 1.0 / (mlx->player.planoX * mlx->player.dirY - mlx->player.dirX * mlx->player.planoY);
		mlx->sprite_calc.transX = mlx->sprite_calc.invdet * (mlx->player.dirY * mlx->sprite_calc.x  - mlx->player.dirX * mlx->sprite_calc.y);
		mlx->sprite_calc.transY = mlx->sprite_calc.invdet * (-mlx->player.planoY * mlx->sprite_calc.x + mlx->player.planoX * mlx->sprite_calc.y);
		mlx->sprite_calc.screen_x = ((mlx->s_width / 2) * (1 + mlx->sprite_calc.transX / mlx->sprite_calc.transY));
		calcule_sprite_width(mlx);
		calcule_sprite_height(mlx);
		draw_all_sprites(mlx);
		i++;
	}
}
