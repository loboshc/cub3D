/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:48:54 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/21 19:09:38 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_mlx *mlx)
{
	mlx->textno.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_north, &mlx->textno.width, &mlx->textno.height);
	mlx->textno.addr = mlx_get_data_addr(mlx->textno.img_ptr, &mlx->textno.bpp, &mlx->textno.size, &mlx->textno.endi);

	mlx->textso.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_south, &mlx->textso.width, &mlx->textso.height);
	mlx->textso.addr = mlx_get_data_addr(mlx->textso.img_ptr, &mlx->textso.bpp, &mlx->textso.size, &mlx->textso.endi);

	mlx->textwe.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_west, &mlx->textwe.width, &mlx->textwe.height);
	mlx->textwe.addr = mlx_get_data_addr(mlx->textwe.img_ptr, &mlx->textwe.bpp, &mlx->textwe.size, &mlx->textwe.endi);

	mlx->textea.img_ptr = mlx_xpm_file_to_image(mlx->mlx, mlx->path_east, &mlx->textea.width, &mlx->textea.height);
	mlx->textea.addr = mlx_get_data_addr(mlx->textea.img_ptr, &mlx->textea.bpp, &mlx->textea.size, &mlx->textea.endi);
}