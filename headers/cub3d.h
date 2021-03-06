/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:06:42 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/07/21 13:10:21 by dlobos-m         ###   ########.fr       */
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
# include "mlx.h"
# include "libft.h"
# include "sys/stat.h"
# include <math.h>
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
# define MOVE_SPEED 0.089


typedef struct s_sprite
{
    int x;
    int y;
}               t_sprite;

typedef struct s_player
{
	double posX;
    double posY;
    double dirX;
    double dirY;
    double planoX;
    double planoY;
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
    int    *addr;
    int     bpp;
    int     size;
    int     endi;
    int     height;
    int     width;
    double  wall;
    int     text_y;
    int     text_x;
}               t_text;

typedef struct  s_sprite_calc
{
    double  x;
    double  y;
    double	invdet;
    double			transX;
	double			transY;
    int     screen_x;
    int		height;
    int     width;
    int     drawstartx;
    int     drawendx;
    int     drawstarty;
    int     drawendy;
    int     textX;
    int     textY;
    int     d;
    unsigned int color;

}                t_sprite_calc;

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
    double  *zbuffer;
    int move_w;
    int move_s;
    int move_a;
    int move_d;
    int move_rl;
    int move_rr;
    double move_speed;
    int sprite_num;
    double step;
    double texPos;
    int text_x;
    int *texture;
    int textY;
    int size_line;
    int color;
    char    *path_north;
    char    *path_south;
    char    *path_west;
    char    *path_east;
    char    *path_sprite;
    int f;
    int x;
    int p;
    int max_width[200];
    int read_map;
    int lastline;
    int row;
    int sp_num;
    int m_x;
    int m_y;
    int i;
    t_player player;
    t_floor  floor;
    t_sky    sky;
    t_text   textno;
    t_text   textso;
    t_text   textwe;
    t_text   textea;
    t_text   textsp;
    t_sprite *sprite;
    t_sprite *sprite_sorted;
    t_sprite_calc sp_calc;
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
void	calculate_textures(t_mlx *mlx, int x);
void    put_pixel(t_mlx *mlx, int color, int x);
void	draw_sprites(t_mlx *mlx);
void    put_pixel_sprite(t_mlx *mlx, int color, int x, int y);
void	select_texture(t_mlx *mlx);
void	draw_all(t_mlx *mlx, int x);
void	calculations_sprites(t_mlx *mlx, int y);
void	calcule_sprite_width(t_mlx *mlx);
void	calcule_sprite_height(t_mlx *mlx);
void	sort_sprites(t_mlx *mlx, int *sprite_order);
void	check_corners(t_mlx *mlx, int y, int x);
void    check_rows(t_mlx *mlx, int y, int x);
void	check_filling(t_mlx *mlx, int y, int x);
void    check_error_map(t_mlx *mlx);
void    sprite_fill_map(t_mlx *mlx, int y, int x); 
void    get_info(char *argv, t_mlx *mlx);
int		key_pressed(int key, t_mlx *mlx);
int     key_release(int key, t_mlx *mlx);
int		exit_game(t_mlx *mlx);
void	create_map(t_mlx *mlx);
void	init_values(t_mlx *mlx);
void	init_value2(t_mlx *mlx);
void	init_mlx(t_mlx *mlx);
void	ft_screen_shot(t_mlx *mlx);

#endif