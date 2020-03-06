/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:48:54 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/03/05 13:17:31 by dlobos-m         ###   ########.fr       */
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

void	calculate_texture_north(t_mlx *mlx)
{
	if (mlx->side == 0)
		mlx->textno.wall = mlx->player.posY + mlx->perpWallDist * mlx->rayDirY;
	else
		mlx->textno.wall = mlx->player.posX + mlx->perpWallDist * mlx->rayDirX;
	mlx->textno.wall -= floor(mlx->textno.wall);
	mlx->textno.text_x = (int)(mlx->textno.wall * (double)(mlx->textno.width));
	if (mlx->side == 0 && mlx->rayDirX > 0)
		mlx->textno.text_x = mlx->textno.width - mlx->textno.text_x - 1;
	if (mlx->side == 1 && mlx->rayDirY < 0)
		mlx->textno.text_x = mlx->textno.width - mlx->textno.text_x - 1;
}

void	calculate_texture_south(t_mlx *mlx)
{
	if (mlx->side == 0)
		mlx->textso.wall = mlx->player.posY + mlx->perpWallDist * mlx->rayDirY;
	else
		mlx->textso.wall = mlx->player.posX + mlx->perpWallDist * mlx->rayDirX;
	mlx->textso.wall -= floor(mlx->textso.wall);
	mlx->textso.text_x = (int)(mlx->textso.wall * (double)(mlx->textso.width));
	if (mlx->side == 0 && mlx->rayDirX > 0)
		mlx->textso.text_x = mlx->textso.width - mlx->textso.text_x - 1;
	if (mlx->side == 1 && mlx->rayDirY < 0)
		mlx->textso.text_x = mlx->textso.width - mlx->textso.text_x - 1;
}

void	calculate_texture_east(t_mlx *mlx)
{
	if (mlx->side == 0)
		mlx->textea.wall = mlx->player.posY + mlx->perpWallDist * mlx->rayDirY;
	else
		mlx->textea.wall = mlx->player.posX + mlx->perpWallDist * mlx->rayDirX;
	mlx->textea.wall -= floor(mlx->textea.wall);
	mlx->textea.text_x = (int)(mlx->textea.wall * (double)(mlx->textea.width));
	if (mlx->side == 0 && mlx->rayDirX > 0)
		mlx->textea.text_x = mlx->textea.width - mlx->textea.text_x - 1;
	if (mlx->side == 1 && mlx->rayDirY < 0)
		mlx->textea.text_x = mlx->textea.width - mlx->textea.text_x - 1;
}

void	calculate_texture_west(t_mlx *mlx)
{
	if (mlx->side == 0)
		mlx->textwe.wall = mlx->player.posY + mlx->perpWallDist * mlx->rayDirY;
	else
		mlx->textwe.wall = mlx->player.posX + mlx->perpWallDist * mlx->rayDirX;
	mlx->textwe.wall -= floor(mlx->textwe.wall);
	mlx->textwe.text_x = (int)(mlx->textwe.wall * (double)(mlx->textwe.width));
	if (mlx->side == 0 && mlx->rayDirX > 0)
		mlx->textwe.text_x = mlx->textwe.width - mlx->textwe.text_x - 1;
	if (mlx->side == 1 && mlx->rayDirY < 0)
		mlx->textwe.text_x = mlx->textwe.width - mlx->textwe.text_x - 1;
}

void	calculate_textures(t_mlx *mlx)
{
	calculate_texture_north(mlx);
	calculate_texture_south(mlx);
	calculate_texture_east(mlx);
	calculate_texture_west(mlx);
}
