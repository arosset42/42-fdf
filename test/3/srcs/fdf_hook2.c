/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:35:07 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/02 10:39:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			key_hook_zoom(int keycode, t_map *map)
{
	if (keycode == ZOOM_IN_KEY)
	{
		map->distance += 1;
		fdf_new_image(map);
	}
	else if (keycode == ZOOM_OUT_KEY)
	{
		map->distance -= 1;
		if (map->distance < 1)
			map->distance = 1;
		fdf_new_image(map);
	}
}

void			key_hook_colors(int keycode, t_map *map)
{
	if (keycode == GREEN_KEY)
	{
		map->color = GREEN;
		fdf_new_image(map);
	}
	else if (keycode == GREY_KEY)
	{
		map->color = GREY;
		fdf_new_image(map);
	}
	else if (keycode == BLUE_KEY)
	{
		map->color = BLUE;
		fdf_new_image(map);
	}
	else if (keycode == RED_KEY)
	{
		map->color = RED;
		fdf_new_image(map);
	}
}
