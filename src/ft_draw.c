/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:22:35 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 18:12:58 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_point(t_point *point, t_win *screen, int color)
{
	if (ft_out_window(point) == 1)
	{
		ft_memcpy(&(screen->img_addr[((int)(point->x) * 4) +
			((int)(point->y) * screen->size)]),
			&(color), (size_t)(sizeof(int)));
	}
}

void	init_param(t_point *p1, t_point *p2, double *params)
{
	params[0] = fabs(p1->x - p2->x);
	params[1] = ((p1->x < p2->x) * 2) - 1;
	params[2] = fabs(p1->y - p2->y);
	params[3] = ((p1->y < p2->y) * 2) - 1;
	if (params[0] > params[2])
		params[4] = params[0] * 0.5;
	else
		params[4] = -params[2] * 0.5;
	if (ft_max(params[0], params[2]) > 1)
		params[5] = 1 / (double)(ft_max(params[0], params[2]) - 1);
	else if (ft_max(params[0], params[2]) == 1)
		params[5] = 1;
	else
		params[5] = 0;
	params[6] = 0;
}

void	ft_draw_line(t_point p1, t_point p2, t_win *screen)
{
	int		flag;
	double	params[8];

	init_param(&p1, &p2, params);
	flag = 1;
	if (ft_out_window(&p1) || ft_out_window(&p2))
		while (flag && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
		{
			ft_draw_point(&p1, screen, get_color(screen, &p1, &p2, params[6]));
			params[6] += params[5];
			params[7] = params[4];
			flag = 0;
			if (params[7] > -params[0] && (int)p1.x != (int)p2.x)
			{
				params[4] -= params[2];
				p1.x += params[1];
				flag = 1;
			}
			if (params[7] < params[2] && (int)p1.y != (int)p2.y)
			{
				params[4] += params[0];
				p1.y += params[3];
				flag = 1;
			}
		}
}

void	ft_draw_map(t_win *scr)
{
	int		x;
	int		y;
	t_point	p1;

	y = 0;
	while (y < scr->map->len)
	{
		x = 0;
		while (x < (scr->map->lines[y]->len))
		{
			p1 = (*scr->map->lines[y]->points[x]);
			if (scr->map->lines[y]->points[x + 1] &&
				(x + 1) < (scr->map->lines[y]->len))
				ft_draw_line(p1, *scr->map->lines[y]->points[x + 1], scr);
			if (scr->map->lines[y + 1] && y + 1 < scr->map->len)
			{
				if (scr->map->lines[y + 1]->points[x] &&
					x <= scr->map->lines[y + 1]->len)
					ft_draw_line(p1, *scr->map->lines[y + 1]->points[x], scr);
			}
			x++;
		}
		y++;
	}
}

int		ft_draw(t_win *screen)
{
	screen->img = mlx_new_image(screen->mlx, WIN_W + 100, WIN_H + 100);
	screen->img_addr = mlx_get_data_addr(screen->img,
		&(screen->bits), &(screen->size), &(screen->endian));
	ft_draw_map(screen);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
	ft_display_info(screen);
	mlx_destroy_image(screen->mlx, screen->img);
	return (0);
}
