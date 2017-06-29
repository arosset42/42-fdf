/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:00:42 by arosset           #+#    #+#             */
/*   Updated: 2017/06/29 19:00:43 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_hook(int keycode, t_win *screen)
{
	if (keycode == 53)
		exit(EXIT_FAILURE);
	if (keycode == 126)
		screen->dy -= 10;
	if (keycode == 125)
		screen->dy += 10;
	if (keycode == 124)
		screen->dx += 10;
	if (keycode == 123)
		screen->dx -= 10;

	ft_printf("dx = %d, dy = %d\n", screen->dx, screen->dy);
	mlx_clear_window(screen->mlx, screen->win);
	ft_draw(screen);
	ft_cat(screen);
	ft_printf("keycode = %d\n", keycode);
	return (1);
}
