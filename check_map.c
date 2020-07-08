/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:33:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/08 10:08:15 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_corners2(t_mlx *mlx, int y, int x)
{
	//esquina inferior izquierda
	if (x == 0 && y == mlx->m_height - 1)
	{
		if (mlx->map[y - 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y][x + 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
	//esquina inferior derecha
	else if (y == mlx->m_height - 1 && x == mlx->m_width - 1)
	{
		if (mlx->map[y][x - 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y - 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
}

void	check_corners(t_mlx *mlx, int y, int x)
{
	//esquina superior izquierda
	if (y == 0 && x == 0)
	{
		if (mlx->map[y][x + 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y + 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
	//esquina superior derecha
	else if (y == 0 && x == mlx->m_width - 1)
	{
		if (mlx->map[y][x - 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y + 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
	else
		check_corners2(mlx, y, x);
}

void	check_rows2(t_mlx *mlx, int y, int x)
{
	//fila lateral derecha
	if (x == mlx->m_width - 1 && (y != 0 && y != mlx->m_height - 1))
	{
		if (mlx->map[y - 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y + 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y][x - 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		}
	//fila inferior
	else if (y == mlx->m_height - 1 && (x != 0 && x != mlx->m_width - 1))
	{
		if (mlx->map[y][x - 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y][x + 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y - 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
}

void	check_rows(t_mlx *mlx, int y, int x)
{
	//fila superior
	if (y == 0 && (x != 0 && x != mlx->m_width - 1))
	{
		if (mlx->map[y][x - 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y][x + 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y + 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
	//fila lateral izquierda
	else if (x == 0 && (y != 0 && y != mlx->m_height - 1))
	{
		if (mlx->map[y - 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y + 1][x] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
		if (mlx->map[y][x + 1] == 0)
			error_exit("El mapa debe estar cerrado por muros [1].");
	}
	else
		check_rows2(mlx, y, x);
}

void	check_filling(t_mlx *mlx, int y, int x)
{
	if (mlx->map[y][x - 1] == 0)
		error_exit("El mapa debe estar cerrado por muros [1].");
	if (mlx->map[y][x + 1] == 0)
		error_exit("El mapa debe estar cerrado por muros [1].");
	if (mlx->map[y - 1][x] == 0)
		error_exit("El mapa debe estar cerrado por muros [1].");
	if (mlx->map[y + 1][x] == 0)
		error_exit("El mapa debe estar cerrado por muros [1].");
}
