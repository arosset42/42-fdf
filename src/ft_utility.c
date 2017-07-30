/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:15:00 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 18:15:32 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_center(t_win *screen)
{
	t_point	p;
	int		x;
	int		y;

	p = screen->center;
	y = screen->map->len;
	x = screen->map->lines[y - 1]->len;
	p.x = (screen->map->lines[y - 1]->points[x - 1]->x +
			screen->map->lines[0]->points[0]->x) / 2;
	p.y = (screen->map->lines[y - 1]->points[x - 1]->y +
			screen->map->lines[0]->points[0]->y) / 2;
	screen->center = p;
}

void	ft_init_win(t_win *screen, int x, int y, char *name)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, x, y, name);
}

int		ft_out_window(t_point *point)
{
	if (!(point->x > WIN_W + SHIFT_DIST || point->x <= 0 ||
			point->y > WIN_H + SHIFT_DIST || point->y <= 0))
		return (1);
	else
		return (0);
}

void	adapt_map(t_win *screen)
{
	int		w;
	int		h;
	double	s;

	w = (WIN_W) / 2;
	h = (WIN_H) / 2;
	if (screen->center.x == 0)
		screen->center.x = 10;
	if (screen->center.y == 0)
		screen->center.y = 10;
	if (((screen->center.y) / (screen->center.x)) <= (WIN_H / WIN_W))
		s = w / (screen->center.x);
	else
		s = h / (screen->center.y);
	calc_shift(screen, -screen->center.x + w, -screen->center.y + h, 0);
	calc_scale(screen, s);
	calc_rotation(screen, M_PI / 15, 'z');
	calc_rotation(screen, M_PI / 5, 'x');
	screen->scale = s;
}
