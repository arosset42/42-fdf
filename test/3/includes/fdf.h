/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:38:09 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/15 16:18:52 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define WIN_X				1000
# define WIN_Y				1000
# define DIST				20

/*
** KEYS
*/
# define ESC_KEY			0xff1b
# define RESET_KEY			0x0072

# define ZOOM_IN_KEY 		0x003d
# define ZOOM_OUT_KEY		0x002d

# define UP_KEY				0x08fc
# define DOWN_KEY			0x08fe
# define LEFT_KEY			0x08fb
# define RIGHT_KEY			0x08fd

# define ROT_X_U_KEY		0x0031
# define ROT_X_D_KEY		0x0032
# define ROT_Y_U_KEY		0x0033
# define ROT_Y_D_KEY		0x0034
# define ROT_Z_U_KEY		0x0035
# define ROT_Z_D_KEY		0x0036

/*
** PADCHAR_COLORS 
*/
# define GREEN_KEY			83
# define GREY_KEY			84
# define BLUE_KEY			85
# define RED_KEY			86

/*
** MOOVES
*/
# define UP					-2
# define DOWN				2
# define LEFT				-2
# define RIGHT				2

# define ROT_X_U			-M_PI / 64
# define ROT_X_D			M_PI / 64
# define ROT_Y_U			-M_PI / 64
# define ROT_Y_D			M_PI / 64
# define ROT_Z_U			-M_PI / 64
# define ROT_Z_D			M_PI / 64

/*
** COLORS
*/
# define GREEN				0x00f000
# define GREY				0xa0a00a
# define BLUE				0x00000f
# define RED				0xf00000
# define BLACK				0x000000

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			s;
}					t_point;

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bxp;
	int				s_line;
	int				en;
}					t_img;

typedef struct		s_map
{
	t_mlx			xx;
	t_img			img;
	t_point			center;
	t_point			**points;
	t_point			**pts_cpy;
	int				height;
	int				width;
	int				distance;
	int				color;
}					t_map;

typedef struct		s_matrix
{
	double			a1;
	double			b1;
	double			c1;
	double			d1;
	double			a2;
	double			b2;
	double			c2;
	double			d2;
	double			a3;
	double			b3;
	double			c3;
	double			d3;
	double			a4;
	double			b4;
	double			c4;
	double			d4;
}					t_matrix;

typedef	struct		s_val
{
	t_point			pt;
	t_point			col_pt[2];
	int				color;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				h;
	int				w;
}					t_val;

typedef	struct		s_bres
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e;
	int				e2;
}					t_bres;

/*
** ERRORS
*/
int					ft_argv_error(void);
int					ft_malloc_error(void);
int					ft_map_error(int err);

/*
** FREE
*/
void				ft_free_splitted(char **split);
void				ft_free_points(t_point **points, int h);

/*
** MAP
*/
int					parse_map(char *file);
int					get_map(t_map *map, char *file);

/*
** FDF
*/
int					fdf(t_map *map);
void				fdf_draw(t_map *map);
void				fdf_new_image(t_map *map);

/*
** HOOK
*/
int					key_hook(int keycode, t_map *map);
void				key_hook_zoom(int keycode, t_map *map);
void				key_hook_colors(int keycode, t_map *map);

/*
** MATRIX
*/
void				calc_matrix(t_map *map, t_matrix m);
t_matrix			matrix_traslat(int x, int y, int z);
t_matrix			matrix_rot_x(double teta);
t_matrix			matrix_rot_y(double teta);
t_matrix			matrix_rot_z(double teta);

/*
** COMPLEM
*/
int					out_of_window(t_val val);
t_point				**cpy_pts(t_point **points, int h, int w);
int					get_color(t_val val);
void				fdf_find_center(t_map *map);

/*
** SET
*/
void				set_init_map(t_map *map);
t_bres				set_bres(t_val val);
void				set_val_0(t_val *val, t_map *map, int h, int w);
void				set_val_1(t_val *val, t_map *map, int h, int w);

#endif
