/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:47:49 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/03 16:39:09 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix		matrix_rot_z(double teta)
{
	t_matrix	m;

	m.a1 = cos(teta);
	m.b1 = -sin(teta);
	m.c1 = 0;
	m.d1 = 0;
	m.a2 = sin(teta);
	m.b2 = cos(teta);
	m.c2 = 0;
	m.d2 = 0;
	m.a3 = 0;
	m.b3 = 0;
	m.c3 = 1;
	m.d3 = 0;
	return (m);
}

t_matrix		matrix_rot_y(double teta)
{
	t_matrix	m;

	m.a1 = cos(teta);
	m.b1 = 0;
	m.c1 = sin(teta);
	m.d1 = 0;
	m.a2 = 0;
	m.b2 = 1;
	m.c2 = 0;
	m.d2 = 0;
	m.a3 = -sin(teta);
	m.b3 = 0;
	m.c3 = cos(teta);
	m.d3 = 0;
	return (m);
}

t_matrix		matrix_rot_x(double teta)
{
	t_matrix	m;

	m.a1 = 1;
	m.b1 = 0;
	m.c1 = 0;
	m.d1 = 0;
	m.a2 = 0;
	m.b2 = cos(teta);
	m.c2 = -sin(teta);
	m.d2 = 0;
	m.a3 = 0;
	m.b3 = sin(teta);
	m.c3 = cos(teta);
	m.d3 = 0;
	return (m);
}

t_matrix		matrix_traslat(int x, int y, int z)
{
	t_matrix	m;

	m.d1 = x;
	m.d2 = y;
	m.d3 = z;
	m.a1 = 1;
	m.a2 = 0;
	m.a3 = 0;
	m.b1 = 0;
	m.b2 = 1;
	m.b3 = 0;
	m.c1 = 0;
	m.c2 = 0;
	m.c3 = 1;
	return (m);
}
