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

/*
** M_PI = 3.141593
*/

# define SIZE_W 20
# define SIZE_H 20
# define SIZE_ALT 5

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

void 	ft_error(int c, char *s);
t_map 	*ft_parse_map(char *av, int fd, char *line);

void	get_center(t_win *screen);

#endif
