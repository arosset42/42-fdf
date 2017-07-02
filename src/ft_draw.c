/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:22:35 by arosset           #+#    #+#             */
/*   Updated: 2017/06/29 19:22:36 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 	ft_modif_pts(t_point *pts)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = (sqrt(2) / 2) * (pts->x - pts->y);
	tmp_y = ((0.82 * pts->z) - (1 / sqrt(6)) * (pts->x + pts->y));

	pts->x = tmp_x;
	pts->y = tmp_y;
}

int		ft_draw_line(t_point *p1, t_point *p2, t_win *screen)
{
	double 		x;
	double		tmp_x;
	double		tmp_y;
	int		dec;

	dec = 500;

	tmp_x = (sqrt(2) / 2) * (p2->x - p2->y);
	tmp_y = ((0.82 * p2->z) - (1 / sqrt(6)) * (p2->x + p2->y));
	x = p1->x;
	printf("\033[33m x1 = %f, y1 =%f z1 = %f ",p1->x ,p1->y, p1->z );
	printf("\033[32m x2 = %f, y2 =%f z2 = %f \033[00m",p2->x ,p2->y, p2->z );
	printf("\033[31m x2 = %f, y2 =%f z2 = %f \033[00m\n",tmp_x ,tmp_y, p2->z );

	while (x <= tmp_x)
	{
		mlx_pixel_put(screen->mlx, screen->win, x + dec , p1->y + ((tmp_y - p1->y) * (x - p1->x)) / (tmp_x - x) + dec, 0xFFFFFF);
		x++;
	}

}

void 	ft_draw(t_win *screen)
{
	int		i;
	int		j;
	int		dec;

	dec = 500;
	i = 0;
	while (i < screen->map->len)
	{
		j = 0;
		while (j < screen->map->lines[i]->len - 1)
		{
			if (screen->map->lines[i]->points[j]->z > 0)
				printf("\033[31mx = %f, y =%f z = %f\033[00m ",screen->map->lines[i]->points[j]->x ,screen->map->lines[i]->points[j]->y, screen->map->lines[i]->points[j]->z );
			else
				printf("x = %f, y =%f z = %f ",screen->map->lines[i]->points[j]->x ,screen->map->lines[i]->points[j]->y, screen->map->lines[i]->points[j]->z );
			ft_modif_pts(screen->map->lines[i]->points[j]);
			printf("xi = %f, yi =%f \n",screen->map->lines[i]->points[j]->x ,screen->map->lines[i]->points[j]->y );
			if (screen->map->lines[i]->points[j]->z > 0)
				mlx_pixel_put(screen->mlx, screen->win, screen->map->lines[i]->points[j]->x + dec, screen->map->lines[i]->points[j]->y + dec, 0xFB3D3D);
			else
				mlx_pixel_put(screen->mlx, screen->win, screen->map->lines[i]->points[j]->x  +dec, screen->map->lines[i]->points[j]->y + dec, 0xFFFFFF);
			if (screen->map->lines[i]->points[j + 1])
				ft_draw_line(screen->map->lines[i]->points[j], screen->map->lines[i]->points[j + 1] ,screen);
			//ft_draw_line(screen->map->lines[i]->points[j]->x + screen->dx, screen->map->lines[i]->points[j]->y + screen->dy,
				//			screen->map->lines[i + 1]->points[j]->x + screen->dx, screen->map->lines[i + 1]->points[j]->y + screen->dy, screen);
			j++;
		}
		i++;
	}
}
