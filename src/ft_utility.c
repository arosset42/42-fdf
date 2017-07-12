/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:15:00 by arosset           #+#    #+#             */
/*   Updated: 2017/06/28 21:15:22 by arosset          ###   ########.fr       */
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

void 	ft_init_win(t_win *screen, int x, int y, char *name)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, x, y, name);
}
