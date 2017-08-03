/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:16:47 by arosset           #+#    #+#             */
/*   Updated: 2017/07/30 17:34:33 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "color_rgb.h"

/*
** Params
*/

# define THEMES 5

# define WIN_W 1980
# define WIN_H 1080

# define SIZE_W 100
# define SIZE_H 100
# define SIZE_ALT 5

/*
** Deplacement
*/

# define SHIFT_DIST 10
# define MOVE_UP -SHIFT_DIST
# define MOVE_DOWN SHIFT_DIST
# define MOVE_LEFT -SHIFT_DIST
# define MOVE_RIGHT SHIFT_DIST

# define ZOOM_AMOUNT 0.1
# define SCALE 1.0
# define MOVE_ZOOM_IN (SCALE + ZOOM_AMOUNT)
# define MOVE_ZOOM_OUT (SCALE - ZOOM_AMOUNT)
# define LIMIT_ZOOM_IN 20.0
# define LIMIT_ZOOM_OUT 0.008

# define ROT_DEGREE 90
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
# define KEY_ROT_Z_U 12
# define KEY_ROT_Z_D 14

# define KEY_COLOR_U 47
# define KEY_COLOR_D 43

typedef struct	s_color
{
	int			c1;
	int			c2;
}				t_color;

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
	int			scale_p;
}				t_win;

typedef struct	s_matrice
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
}				t_matrice;

void			ft_fdf(char *av);

void			ft_error(int c, char *s);
t_map			*ft_parse_map(char *av, int fd, char *line);

void			get_center(t_win *screen);
void			ft_init_win(t_win *screen, int x, int y, char *name);
int				ft_out_window(t_point *point);
void			adapt_map(t_win *screen);

int				ft_key_hook(int keycode, t_win *screen);

int				ft_draw(t_win *screen);

void			calc_point(t_point *p, t_matrice *m, t_win *screen);
void			calc_all_points(t_matrice *m, t_win *screen);
void			calc_rotation(t_win *screen, double rot, char axis);
void			calc_shift(t_win *screen, double x, double y, double z);
void			calc_scale(t_win *screen, double scale);

t_matrice		*matrice_rotation_x(double theta);
t_matrice		*matrice_rotation_y(double theta);
t_matrice		*matrice_rotation_z(double theta);
t_matrice		*matrice_shift(double tx, double ty, double tz);
t_matrice		*matrice_scale(double scale);

int				**choose_color(void);
int				get_color(t_win *pic, t_point *p1, t_point *p2, double alpha);

void			ft_display_cmd(t_win *s);
void 			ft_display_zoom(t_win *s);

#endif
