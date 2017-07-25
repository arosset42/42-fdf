/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:28:38 by arosset           #+#    #+#             */
/*   Updated: 2017/07/25 22:28:40 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	*matrix_rotation_x(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error(4, 0);
	m->x1 = 1;
	m->y2 = cos(theta);
	m->y3 = -sin(theta);
	m->z2 = sin(theta);
	m->z3 = cos(theta);
	return (m);
}

t_matrix	*matrix_rotation_y(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error(4, 0);
	m->x1 = cos(theta);
	m->x3 = sin(theta);
	m->y2 = 1;
	m->z1 = -sin(theta);
	m->z3 = cos(theta);
	return (m);
}

t_matrix	*matrix_rotation_z(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error(4, 0);
	m->x1 = cos(theta);
	m->x2 = -sin(theta);
	m->y1 = sin(theta);
	m->y2 = cos(theta);
	m->z3 = 1;
	return (m);
}

t_matrix	*matrix_shift(double tx, double ty, double tz)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error(4, 0);
	m->x4 = tx;
	m->y4 = ty;
	m->z4 = tz;
	m->x1 = 1;
	m->y2 = 1;
	m->z3 = 1;
	return (m);
}

t_matrix	*matrix_scale(double scale)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error(4, 0);
	m->x1 = scale;
	m->y2 = scale;
	m->z3 = scale;
	return (m);
}
