/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:06:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/24 20:01:10 by dlobos-m         ###   ########.fr       */
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
//# define MV_SPEED 0.039
# define ROT_SPEED 0.0445
# define KEY_ESC 53
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

typedef struct s_floor
{
    int r;
    int g;
    int b;
}               t_floor;

typedef struct s_sky
{
    int r;
    int g;
    int b;
}               t_sky;

typedef struct s_text
{
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     size;
    int     endi;
    int     height;
    int     width;
}               t_text;

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
    double move_speed;

    char    *path_north;
    char    *path_south;
    char    *path_west;
    char    *path_east;
    char    *path_sprite;
    t_player player;
    t_floor  floor;
    t_sky    sky;
    t_text   textno;
    t_text   textso;
    t_text   textwe;
    t_text   textea;
}              t_mlx;

void	get_info_map(char *line, t_mlx *mlx, int lastline);
void	error_exit(char *s);
void	free_and_null(void *obj);
void	init_player(char *buf, t_mlx *mlx, int *x, int y);
int     ft_raycasting(t_mlx *mlx);
void	move_handler(t_mlx *mlx);
void	get_color_f(t_mlx *mlx, char *line);
void	get_color_s(t_mlx *mlx, char *line);
void	get_textures(t_mlx *mlx, char *line);
void	get_sprite(t_mlx *mlx, char *line);
void	textures(t_mlx *mlx);

#endif