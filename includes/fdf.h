/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:16:47 by arosset           #+#    #+#             */
/*   Updated: 2017/06/23 14:16:54 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/includes/libft.h"
#include <fcntl.h>		//open
#include <sys/stat.h>	//open
#include <sys/types.h>	//open
#include <math.h>
#include <stdio.h>  	//perror
#include <string.h> 	//strerror
#include "../minilibx_macos/mlx.h"

#include "color_rgb.h"

/*
** M_PI = 3.141593
*/

# define WIN_W 1920
# define WIN_H 1080

# define SIZE_W 20
# define SIZE_H 20
# define SIZE_ALT 5

/*
** Deplacement
*/

# define SHIFT_DIST 20
# define MOVE_UP -SHIFT_DIST
# define MOVE_DOWN SHIFT_DIST
# define MOVE_LEFT -SHIFT_DIST
# define MOVE_RIGHT SHIFT_DIST

# define ZOOM_AMOUNT 0.1
# define SCALE 1.0
# define MOVE_ZOOM_IN (SCALE + ZOOM_AMOUNT)
# define MOVE_ZOOM_OUT (SCALE - ZOOM_AMOUNT)
# define LIMIT_ZOOM_IN 20.0
# define LIMIT_ZOOM_OUT 0.015

# define ROT_DEGREE 36
# define MOVE_ROT_X_U -M_PI / ROT_DEGREE
# define MOVE_ROT_X_D M_PI / ROT_DEGREE
# define MOVE_ROT_Y_U -M_PI / ROT_DEGREE
# define MOVE_ROT_Y_D M_PI / ROT_DEGREE
# define MOVE_ROT_Z_U -M_PI / ROT_DEGREE
# define MOVE_ROT_Z_D M_PI / ROT_DEGREE

/*
** KEYCODE
*/

# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_ZOOM_IN 69
# define KEY_ALT_ZOOM_IN 24
# define KEY_ZOOM_OUT 78
# define KEY_ALT_ZOOM_OUT 27

# define KEY_ROT_X_U 1
# define KEY_ROT_X_D 13
# define KEY_ROT_Y_U 0
# define KEY_ROT_Y_D 2
# define KEY_ROT_Z_U 14
# define KEY_ROT_Z_D 12

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_line
{
	t_point		**points;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**lines;
	int			len;
	double		min;
	double		max;
	double		mid;
}				t_map;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		*img;
	t_point		center;
	int			**color;
	int			cnum;
	double		scale;
	char		*img_addr;
	int			bits;
	int			size;
	int			endian;
}				t_win;

typedef struct	s_matrix
{
	double		x1;
	double		x2;
	double		x3;
	double		x4;
	double		y1;
	double		y2;
	double		y3;
	double		y4;
	double		z1;
	double		z2;
	double		z3;
	double		z4;
}				t_matrix;

void 	ft_error(int c, char *s);
t_map 	*ft_parse_map(char *av, int fd, char *line);

void	get_center(t_win *screen);
void 	ft_init_win(t_win *screen, int x, int y, char *name);
int		ft_out_window(t_point *point);
void 	adapt_map(t_win *screen);

int		ft_key_hook(int keycode, t_win *screen);

int		ft_draw(t_win *screen);
void 	ft_cat(t_win *win);

void			calc_point(t_point *p, t_matrix *m, t_win *screen);
void			calc_all_points(t_matrix *m, t_win *screen);
void	calc_rotation(t_win *screen, double rot, char axis);
void	calc_shift(t_win *screen, double x, double y, double z);
void	calc_scale(t_win *screen, double scale);

t_matrix		*matrix_rotation_x(double theta);
t_matrix		*matrix_rotation_y(double theta);
t_matrix		*matrix_rotation_z(double theta);
t_matrix		*matrix_shift(double tx, double ty, double tz);
t_matrix		*matrix_scale(double scale);

#endif
