/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:55:14 by arosset           #+#    #+#             */
/*   Updated: 2017/07/30 15:55:16 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_theme(int i)
{
	if (i == 0)
		return ("White");
	if (i == 1)
		return ("RGB");
	if (i == 2)
		return ("Blue to White");
	if (i == 3)
		return ("Island");
	if (i == 4)
		return ("Moutain");
	return ("Lime");
}

void 	ft_display_zoom(t_win *s)
{
	if (s->scale_p == 1)
		mlx_string_put(s->mlx, s->win, 10, 305, RGB_RED, "Zoom limit max !");
	if (s->scale_p == 2)
		mlx_string_put(s->mlx, s->win, 10, 305, RGB_RED, "Zoom limit min !");
	s->scale_p = 0;
	return;
}

void 	ft_display_footer(t_win *s, int x, int y)
{
	s->footer = mlx_xpm_file_to_image(s->mlx, "42_MS_2.xpm", &x, &y);
	mlx_put_image_to_window(s->mlx, s->win, s->footer, WIN_W - 100, WIN_H - 100);
}

void 	ft_display_info(t_win *s)
{
	ft_display_footer(s, 0, 0);
	mlx_string_put(s->mlx, s->win, 10, WIN_H - 65, RGB_GREEN, "Altitude");
	mlx_string_put(s->mlx, s->win, 10, WIN_H - 25, RGB_GREEN, "MIN   : ");
	mlx_string_put(s->mlx, s->win, 94, WIN_H - 25,
		RGB_WHITE, ft_itoa(s->map->min));
	mlx_string_put(s->mlx, s->win, 10, WIN_H - 45, RGB_GREEN, "MAX   : ");
	mlx_string_put(s->mlx, s->win, 94, WIN_H - 45,
		RGB_WHITE, ft_itoa(s->map->max));
	mlx_string_put(s->mlx, s->win, 150, WIN_H - 25,
		RGB_YELLOW, "Theme : ");
	mlx_string_put(s->mlx, s->win, 230, WIN_H - 25,
		s->color[s->cnum][1], ft_theme(s->cnum));
	mlx_string_put(s->mlx, s->win, 370, WIN_H - 25, RGB_PURPLE, "MAP :");
	mlx_string_put(s->mlx, s->win, 430, WIN_H - 25, RGB_WHITE, s->name_map);

}

void 	ft_display_cmd(t_win *s)
{
	mlx_string_put(s->mlx, s->win, 10, 5, RGB_YELLOW, "CONTROLS");
	mlx_string_put(s->mlx, s->win, 10, 25, RGB_YELLOW, "Rotation :");
	mlx_string_put(s->mlx, s->win, 20, 45, RGB_WHITE, "X : A, D");
	mlx_string_put(s->mlx, s->win, 20, 65, RGB_WHITE, "Y : W, S");
	mlx_string_put(s->mlx, s->win, 20, 85, RGB_WHITE, "Z : Q, E");
	mlx_string_put(s->mlx, s->win, 10, 125,
		RGB_YELLOW, "Translation :");
	mlx_string_put(s->mlx, s->win, 20, 145, RGB_WHITE, "Arrow Keys");
	mlx_string_put(s->mlx, s->win, 10, 185,
		RGB_YELLOW, "Change Color");
	mlx_string_put(s->mlx, s->win, 20, 205, RGB_WHITE, "PREV/NEXT: </>");
	mlx_string_put(s->mlx, s->win, 10, 245, RGB_YELLOW, "Zoom :");
	mlx_string_put(s->mlx, s->win, 20, 265, RGB_WHITE, "In  : +");
	mlx_string_put(s->mlx, s->win, 20, 285, RGB_WHITE, "Out : -");
	mlx_string_put(s->mlx, s->win, 10, 345, RGB_YELLOW, "Esc to exit");
	mlx_string_put(s->mlx, s->win, 1000, WIN_H - 25, RGB_WHITE, "Last Keycode :");
	ft_display_info(s);
}
