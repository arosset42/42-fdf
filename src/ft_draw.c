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

static	void 	ft_draw_line(t_point p1, t_point p2, t_win *screen)
{

}

static 	void	ft_draw_map(t_win *scr)
{
	int		x;
	int		y;
	t_point	p1;

	y = 0;
	while (y < scr->map->len)
	{
		x = 0;
		while (x < scr->map->lines[y]->len)
		{
			p1 = (*scr->map->lines[y]->points[x]);
			if (scr->map->lines[y]->points[x + 1])
				ft_draw_line(p1, *scr->map->lines[y]->points[x + 1], scr);
			if (scr->map->lines[y + 1] && y + 1 < scr->map->len)
			{
				if (scr->map->lines[y + 1]->points[x] && x <= scr->map->lines[y + 1]->len)
					ft_draw_line(p1 , *scr->map->lines[y + 1]->points[x], scr);
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
	mlx_destroy_image(screen->mlx, screen->img);
	return (0);
}
