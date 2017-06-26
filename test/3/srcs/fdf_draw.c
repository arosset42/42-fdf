/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:21:56 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:12:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fdf_find_center(t_map *map)
{
	t_point		p;
	t_point		p1;
	t_point		p2;

	p1.x = (map->points[0][0].x) * map->distance;
	p1.y = (map->points[0][0].y) * map->distance;
	p2.x = (map->points[map->height - 1][map->width - 1].x) * map->distance;
	p2.y = (map->points[map->height - 1][map->width - 1].y) * map->distance;
	p.x = p2.x - p1.x;
	p.y = p2.y - p1.y;
	map->center.x = ((WIN_X - p.x) / 2);
	map->center.y = ((WIN_Y - p.y) / 2);
	map->center.z = 0;
}

static void		fdf_set_dist(t_point point, t_map *map, t_val *val, int t)
{
	val->color = map->color;
	if (t)
	{
		val->x1 = map->distance * point.x + map->center.x;
		val->y1 = map->distance * point.y + map->center.y;
		val->z1 = point.z;
	}
	else
	{
		val->x2 = map->distance * point.x + map->center.x;
		val->y2 = map->distance * point.y + map->center.y;
		val->z2 = point.z;
	}
}

static void		fdf_draw_point(t_map *map, t_val val, int color)
{
	int			i;

	i = ((int)val.x1 * 4) + ((int)val.y1 * map->img.s_line);
	map->img.img[i] = color;
	map->img.img[++i] = color >> 8;
	map->img.img[++i] = color >> 16;
}

static int		fdf_draw_line(t_map *map, t_val val)
{
	t_bres	bres;

	bres = set_bres(val);
	while (1)
	{
		if ((int)val.x1 == (int)val.x2 && (int)val.y1 == (int)val.y2)
			break ;
		if (!out_of_window(val))
			fdf_draw_point(map, val, get_color(val));
		bres.e2 = bres.e;
		if (bres.e2 > -bres.dx)
		{
			bres.e -= bres.dy;
			val.x1 += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.e += bres.dx;
			val.y1 += bres.sy;
		}
	}
	return (0);
}

void			fdf_draw(t_map *map)
{
	t_val	val;

	val.h = -1;
	fdf_find_center(map);
	while (++val.h < map->height)
	{
		val.w = -1;
		while (++val.w < map->width)
		{
			set_val_0(&val, map, val.h, val.w);
			fdf_set_dist(val.pt, map, &val, 1);
			if (val.w < map->width - 1)
			{
				set_val_1(&val, map, val.h, val.w + 1);
				fdf_set_dist(val.pt, map, &val, 0);
				fdf_draw_line(map, val);
			}
			if (val.h < map->height - 1)
			{
				set_val_1(&val, map, val.h + 1, val.w);
				fdf_set_dist(val.pt, map, &val, 0);
				fdf_draw_line(map, val);
			}
		}
	}
}
