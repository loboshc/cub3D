/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:05:48 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/08 12:07:49 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_position(t_mlx *mlx, int y, int x)
{
	if ((y == 0 && x == 0) || (y == 0 && x == mlx->m_width - 1))
		check_corners(mlx, y, x);
	else if ((x == 0 && y == mlx->m_height - 1) ||
		(y == mlx->m_height - 1 && x == mlx->m_width - 1))
		check_corners(mlx, y, x);
	else if ((y == 0 && (x != 0 && x != mlx->m_width - 1)) ||
		(x == 0 && (y != 0 && y != mlx->m_height - 1)))
		check_rows(mlx, y, x);
	else if ((x == mlx->m_width - 1 && (y != 0 && y != mlx->m_height - 1)) ||
		(y == mlx->m_height - 1 && (x != 0 && x != mlx->m_width - 1)))
		check_rows(mlx, y, x);
	else
		check_filling(mlx, y, x);
}

void	check_error_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->m_height)
	{
		x = 0;
		while (x < mlx->m_width)
		{
			if (mlx->map[y][x] == 4)
				check_position(mlx, y, x);
			x++;
		}
		y++;
	}
}
