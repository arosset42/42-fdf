/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:37:58 by arosset           #+#    #+#             */
/*   Updated: 2017/06/26 14:38:01 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

/*
** void 	ft_mlx_draw_foot(t_win *param, char *name_prgm, int win_h, int win_w)
*/

void 	ft_cat(t_win *win)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	y = 0;
	j = 0;//WIN_H - 100;
	while (j <= WIN_H)
	{
		i = 0;
		while (i <= WIN_W)
		{
			if (j >= WIN_H - 100)
				mlx_pixel_put(win->mlx, win->win, i, j, BLEUVERT);
			// else
			// 	mlx_pixel_put(win->mlx, win->win, i, j, WHITE);
			i++;
		}
		j++;
	}
	win->foot = mlx_xpm_file_to_image(win->mlx, "42_MS_2.xpm", &x, &y);
	mlx_put_image_to_window(win->mlx, win->win, win->foot, WIN_W - 110, WIN_H - 100);
	// win->bordel = mlx_xpm_file_to_image(win->mlx, "test.xpm", &x, &y);
	// mlx_put_image_to_window(win->mlx, win->win, win->bordel, -10, 00);
}

int		main(int ac, char **av)
{
	t_win	*screen;
	t_map	*map;


	if (ac == 2)
	{
		if (!(screen = (t_win *)malloc(sizeof(t_win))))
			ft_error(4, 0);
		map = ft_parse_map(av[1], 0, NULL);
		if (map->len == 0 || map->lines[0]->len == 0)
			ft_error(3, 0);
		printf("len = %d, min %f, max %f, mid %f\n", map->len, map->min, map->max, map->mid);
		screen->map = map;
		get_center(screen);
		ft_init_win(screen, WIN_W, WIN_H, "42 FDF");
		printf("Start draw\n");
		ft_cat(screen);
		mlx_expose_hook(screen->win, ft_draw, screen);
		mlx_key_hook(screen->win, ft_key_hook, screen);
		mlx_loop(screen->mlx);
	}
	else
		ft_error(1, 0);
	return (0);
}
