/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:52:02 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/25 21:38:05 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	exit(EXIT_FAILURE);
}

void	free_and_null(void *obj)
{
	free(obj);
	obj = NULL;
}

void    put_pixel(t_mlx *mlx, int color, int x)
{
    int             i;
    unsigned int    j;
    i = 0;
    j = x * (mlx->bit / 8) + mlx->drawStar * mlx->size;
    while(i < (mlx->bit/ 8))
    {
        mlx->addr_img[j + i] = (char)color;
        color >>= 8;
        i++;
    }
}
