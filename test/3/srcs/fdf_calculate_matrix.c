/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:50:42 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/03 17:26:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		op_matrix(t_point *p, t_matrix m)
{
	t_point		tmp;

	tmp.x = p->x * m.a1 + p->y * m.b1 + p->z * m.c1 + p->s * m.d1;
	tmp.y = p->x * m.a2 + p->y * m.b2 + p->z * m.c2 + p->s * m.d2;
	tmp.z = p->x * m.a3 + p->y * m.b3 + p->z * m.c3 + p->s * m.d3;
	p->x = tmp.x;
	p->y = tmp.y;
	p->z = tmp.z;
}

void			calc_matrix(t_map *map, t_matrix m)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			op_matrix(&map->points[y][x], m);
		}
	}
}
