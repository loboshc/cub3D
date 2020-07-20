/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:32:24 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/20 10:33:21 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_mlx *mlx)
{
	mlx->textno.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_north,
	&mlx->textno.width, &mlx->textno.height);
	mlx->textno.addr = (int*)mlx_get_data_addr(mlx->textno.img_ptr,
	&mlx->textno.bpp, &mlx->textno.size, &mlx->textno.endi);
	mlx->textso.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_south,
	&mlx->textso.width, &mlx->textso.height);
	mlx->textso.addr = (int*)mlx_get_data_addr(mlx->textso.img_ptr,
	&mlx->textso.bpp, &mlx->textso.size, &mlx->textso.endi);
	mlx->textwe.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_west,
	&mlx->textwe.width, &mlx->textwe.height);
	mlx->textwe.addr = (int*)mlx_get_data_addr(mlx->textwe.img_ptr,
	&mlx->textwe.bpp, &mlx->textwe.size, &mlx->textwe.endi);
	mlx->textea.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_east,
	&mlx->textea.width, &mlx->textea.height);
	mlx->textea.addr = (int*)mlx_get_data_addr(mlx->textea.img_ptr,
	&mlx->textea.bpp, &mlx->textea.size, &mlx->textea.endi);
	mlx->textsp.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_sprite,
	&mlx->textsp.width, &mlx->textsp.height);
	mlx->textsp.addr = (int*)mlx_get_data_addr(mlx->textsp.img_ptr,
	&mlx->textsp.bpp, &mlx->textsp.size, &mlx->textsp.endi);
}

void	select_texture2(t_mlx *mlx)
{
	mlx->step = 1.0 * mlx->textno.height / mlx->lineHeight;
	mlx->texture = mlx->textno.addr;
	mlx->text_x = mlx->textno.text_x;
	mlx->size_line = mlx->textno.size;
}

void	select_texture(t_mlx *mlx)
{
	if (mlx->side == 1 && mlx->rayDirY > 0)
	{
		mlx->step = 1.0 * mlx->textea.height / mlx->lineHeight;
		mlx->texture = mlx->textea.addr;
		mlx->text_x = mlx->textea.text_x;
		mlx->size_line = mlx->textea.size;
	}
	else if (mlx->side == 1 && mlx->rayDirY < 0)
	{
		mlx->step = 1.0 * mlx->textwe.height / mlx->lineHeight;
		mlx->texture = mlx->textwe.addr;
		mlx->text_x = mlx->textwe.text_x;
		mlx->size_line = mlx->textwe.size;
	}
	else if (mlx->side == 0 && mlx->rayDirX > 0)
	{
		mlx->step = 1.0 * mlx->textso.height / mlx->lineHeight;
		mlx->texture = mlx->textso.addr;
		mlx->text_x = mlx->textso.text_x;
		mlx->size_line = mlx->textso.size;
	}
	else
		select_texture2(mlx);
	mlx->texPos = (mlx->drawStar - mlx->s_height / 2
	+ mlx->lineHeight / 2) * mlx->step;
}
