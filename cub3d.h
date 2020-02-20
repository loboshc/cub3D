/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:06:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/20 20:53:15 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "sys/stat.h"
# include <math.h>
# define MV_SPEED 0.099
# define ROT_SPEED 0.0745
# define M_KEY_PRESS (1L<<0)
# define M_KEY_RELEASE (1L<<1)
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124


typedef struct s_player
{
	double posX;//Posicion del jugador 
    double posY;//Posicion del jugador 
    double dirX;//Vector de direccion del jugador solo cambiar cuando giras 
    double dirY;//Vector de direccion del jugador solo cuando giras o rotas
    double planoX;//para los calculos en 2d
    double planoY;//para los calculos en 2d
}				t_player;
typedef struct s_mlx
{
    int     fd;
    void    *mlx;
    void    *mlx_window;
    int     s_width;
    int     s_height;
    int     m_width;
    int     m_height;
    int     **map;
    double  cameraX;
    double rayDirX;
    double rayDirY;
    int     mapX;
    int     mapY;
    double sideDistX;
    double sideDistY;
    int     stepX;
    int     stepY;
    int     hit;
    int     side;
    double  deltaDistX;
    double  deltaDistY;
    double  perpWallDist;
    int     drawStar;
    int drawEnd;
    int lineHeight;
    void *img;
    char *addr_img;
    int bit;
    int size;
    int e;
    
    int move_w;
    int move_s;
    int move_a;
    int move_d;
    int move_rl;
    int move_rr;
    t_player player;
}              t_mlx;

void	get_info_map(char *line, t_mlx *mlx, int lastline);
void	error_exit(char *s);
void	free_and_null(void *obj);
void	init_player(char *buf, t_mlx *mlx, int *x, int y);
int     ft_raycasting(t_mlx *mlx);
void	move_handler(t_mlx *mlx);

#endif