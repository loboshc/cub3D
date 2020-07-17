/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:07:50 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/17 13:10:43 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_data_header(t_mlx *mlx, int size, int fd)
{
	unsigned char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(mlx->s_width);
	header[19] = (unsigned char)(mlx->s_width >> 8);
	header[20] = (unsigned char)(mlx->s_width >> 16);
	header[21] = (unsigned char)(mlx->s_width >> 24);
	header[22] = (unsigned char)(-mlx->s_height);
	header[23] = (unsigned char)(-mlx->s_height >> 8);
	header[24] = (unsigned char)(-mlx->s_height >> 16);
	header[25] = (unsigned char)(-mlx->s_height >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void	ft_screen_shot(t_mlx *mlx)
{
	int		fd;
	int		res;
	int		size;
	char	*tmp;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777)) < 0)
		error_exit("No se puede creear la captura de pantalla.");
	res = mlx->s_width;
	size = 54 + (res + mlx->s_height) * 4;
	write_data_header(mlx, size, fd);
	tmp = (char *)mlx->addr_img;
	write(fd, tmp, (res * mlx->s_height * 4));
	close(fd);
	exit(EXIT_SUCCESS);
}
