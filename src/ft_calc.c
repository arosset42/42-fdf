/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:26:19 by arosset           #+#    #+#             */
/*   Updated: 2017/07/25 22:26:22 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_point(t_point *p, t_matrice *m, t_win *screen)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	p->x -= screen->center.x;
	p->y -= screen->center.y;
	tmp_x = p->x * m->x1 + p->y * m->x2 + p->z * m->x3 + m->x4;
	tmp_y = p->x * m->y1 + p->y * m->y2 + p->z * m->y3 + m->y4;
	tmp_z = p->x * m->z1 + p->y * m->z2 + p->z * m->z3 + m->z4;
	p->x = tmp_x;
	p->y = tmp_y;
	p->z = tmp_z;
	p->x += screen->center.x;
	p->y += screen->center.y;
}

void	calc_all_points(t_matrice *m, t_win *screen)
{
	int	x;
	int	y;

	y = 0;
	while (y < screen->map->len)
	{
		x = 0;
		while (x < (screen->map->lines[y]->len))
		{
			calc_point(screen->map->lines[y]->points[x], m, screen);
			x++;
		}
		y++;
	}
}

void	calc_rotation(t_win *screen, double rot, char axis)
{
	t_matrice	*m_rot;

	if (axis == 'x')
		m_rot = matrice_rotation_x(rot);
	else if (axis == 'y')
		m_rot = matrice_rotation_y(rot);
	else
		m_rot = matrice_rotation_z(rot);
	calc_all_points(m_rot, screen);
	free(m_rot);
}

void	calc_shift(t_win *screen, double x, double y, double z)
{
	t_matrice	*m_shift;

	m_shift = matrice_shift(x, y, z);
	calc_all_points(m_shift, screen);
	get_center(screen);
	free(m_shift);
}

void	calc_scale(t_win *screen, double scale)
{
	t_matrice	*m_scale;

	m_scale = matrice_scale(scale);
	calc_all_points(m_scale, screen);
	free(m_scale);
}
