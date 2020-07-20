/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:41:05 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/20 10:35:08 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_pixel(t_mlx *mlx)
{
	mlx->drawStar = (mlx->lineHeight * -1) / 2 + mlx->s_height / 2;
	if (mlx->drawStar < 0)
		mlx->drawStar = 0;
	mlx->drawEnd = mlx->lineHeight / 2 + mlx->s_height / 2;
	if (mlx->drawEnd >= mlx->s_height)
		mlx->drawEnd = mlx->s_height - 1;
}

void	draw_colors(t_mlx *mlx, int x)
{
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

void	draw_textures(t_mlx *mlx, int x)
{
	while (mlx->drawStar < mlx->drawEnd)
	{
		mlx->textY = (int)mlx->texPos & (64 - 1);
		mlx->texPos += mlx->step;
		mlx->color = mlx->texture[mlx->size_line / 4 *
		mlx->textY + mlx->text_x];
		put_pixel(mlx, mlx->color, x);
		mlx->drawStar++;
	}
}

void	draw_all(t_mlx *mlx, int x)
{
	int n;

	n = 0;
	calculate_pixel(mlx);
	select_texture(mlx);
	while (n < mlx->drawStar)
	{
		mlx->addr_img[4 * (x + n * mlx->s_width)] = (char)mlx->sky.b;
		mlx->addr_img[4 * (x + n * mlx->s_width) + 1] = (char)mlx->sky.g;
		mlx->addr_img[4 * (x + n++ * mlx->s_width) + 2] = (char)mlx->sky.r;
	}
	if (mlx->f)
		draw_colors(mlx, x);
	else
		draw_textures(mlx, x);
	while (mlx->drawEnd < mlx->s_height)
	{
		mlx->addr_img[4 * (x + mlx->drawEnd *
		mlx->s_width)] = (char)mlx->floor.b;
		mlx->addr_img[4 * (x + mlx->drawEnd *
		mlx->s_width) + 1] = (char)mlx->floor.g;
		mlx->addr_img[4 * (x + mlx->drawEnd++
		* mlx->s_width) + 2] = (char)mlx->floor.r;
	}
}
