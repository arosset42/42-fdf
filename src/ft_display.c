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
		return ("RGB");
	if (i == 1)
		return ("Black to white");
	if (i == 2)
		return ("Island");
	if (i == 3)
		return ("IGN");
	return ("Mountain");
}

void 	ft_display_info(t_win *s)
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
	mlx_string_put(s->mlx, s->win, 10, 245,
		RGB_YELLOW, "Esc to Exit");
	mlx_string_put(s->mlx, s->win, 10, WIN_H - 25, RGB_WHITE, "MIN   : ");
	mlx_string_put(s->mlx, s->win, 94, WIN_H - 25,
		RGB_WHITE, ft_itoa(s->map->min));
	mlx_string_put(s->mlx, s->win, 10, WIN_H - 45, RGB_WHITE, "MAX   : ");
	mlx_string_put(s->mlx, s->win, 94, WIN_H - 45,
		RGB_WHITE, ft_itoa(s->map->max));
	mlx_string_put(s->mlx, s->win, 150, WIN_H - 25,
		RGB_YELLOW, "Theme: ");
	mlx_string_put(s->mlx, s->win, 210, WIN_H - 25,
		s->color[s->cnum][2], ft_theme(s->cnum));
}
