/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   footer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:53:35 by arosset           #+#    #+#             */
/*   Updated: 2017/07/20 14:53:37 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
