/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:37:40 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:16:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			set_init_map(t_map *map)
{
	calc_matrix(map, matrix_rot_z(6 * ROT_Z_U));
	calc_matrix(map, matrix_rot_x(18 * ROT_X_D));
}

t_bres			set_bres(t_val val)
{
	t_bres		bres;

	bres.dx = ft_abs(val.x2 - val.x1);
	bres.dy = ft_abs(val.y2 - val.y1);
	bres.sx = (val.x1 < val.x2 ? 1 : -1);
	bres.sy = (val.y1 < val.y2 ? 1 : -1);
	bres.e = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
	return (bres);
}

void			set_val_0(t_val *val, t_map *map, int h, int w)
{
	val->pt = map->points[h][w];
	val->col_pt[0] = map->pts_cpy[h][w];
}

void			set_val_1(t_val *val, t_map *map, int h, int w)
{
	val->pt = map->points[h][w];
	val->col_pt[1] = map->pts_cpy[h][w];
}
