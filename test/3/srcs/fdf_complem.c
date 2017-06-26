/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_complem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:38:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:17:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				get_color(t_val val)
{
	int			col;

	col = ((val.col_pt[0].z) + (val.col_pt[1].z)) * 9;
	if (col <= 0)
		col *= -1;
	return (val.color + col);
}

t_point			**cpy_pts(t_point **points, int h, int w)
{
	t_point		**pts_cpy;
	int			x;
	int			y;

	y = -1;
	if ((pts_cpy = (t_point**)malloc(sizeof(t_point*) * h)) == NULL)
		return (pts_cpy);
	while (++y < h)
	{
		x = -1;
		if ((pts_cpy[y] = (t_point*)malloc(sizeof(t_point) * w)) == NULL)
			return (pts_cpy);
		while (++x < w)
			pts_cpy[y][x] = points[y][x];
	}
	return (pts_cpy);
}

int				out_of_window(t_val val)
{
	if (val.x1 < 0 || val.x1 > WIN_X || val.y1 < 0 || \
			val.y1 > WIN_Y)
		return (1);
	return (0);
}

void			fdf_new_image(t_map *map)
{
	map->img.img_ptr = mlx_new_image(map->xx.mlx_ptr, WIN_X + 50, WIN_Y + 50);
	map->img.img = mlx_get_data_addr(map->img.img_ptr, &map->img.bxp, \
			&map->img.s_line, &map->img.en);
	fdf_draw(map);
	mlx_put_image_to_window(map->xx.mlx_ptr, map->xx.mlx_win, map->img.img_ptr,\
			0, 0);
	mlx_destroy_image(map->xx.mlx_ptr, map->img.img_ptr);
}
