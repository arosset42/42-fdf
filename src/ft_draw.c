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

int		ft_draw_line(int x1, int y1, int x2, int y2, t_win *screen)
{
	int x;

		x = x1;
		while (x <= x2)
		{
			mlx_pixel_put(screen->mlx, screen->win, x, y1 + ((y2-y1) * (x-x1))/(x2-x1), 0xFFFFFF);
			x++;
		}

}

void 	ft_draw(t_win *screen)
{
	int		i;
	int		j;

	i = 0;
	while (i < screen->map->len)
	{
		j = 0;
		while (j < screen->map->lines[i]->len - 1)
		{
			mlx_pixel_put(screen->mlx, screen->win, screen->map->lines[i]->points[j]->x + screen->dx, screen->map->lines[i]->points[j]->y + screen->dy, 0xFB3D3D);
			ft_draw_line(screen->map->lines[i]->points[j]->x + screen->dx, screen->map->lines[i]->points[j]->y + screen->dy,
							screen->map->lines[i]->points[j + 1]->x + screen->dx, screen->map->lines[i]->points[j + 1]->y + screen->dy, screen);
			//ft_draw_line(screen->map->lines[i]->points[j]->x + screen->dx, screen->map->lines[i]->points[j]->y + screen->dy,
				//			screen->map->lines[i + 1]->points[j]->x + screen->dx, screen->map->lines[i + 1]->points[j]->y + screen->dy, screen);
			j++;
		}
		i++;
	}
}
