/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:22:21 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:20:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		key_hook_rot_z(int keycode, t_map *map)
{
	if (keycode == ROT_Z_U_KEY)
	{
		calc_matrix(map, matrix_rot_z(ROT_Z_U));
		fdf_new_image(map);
	}
	else if (keycode == ROT_Z_D_KEY)
	{
		calc_matrix(map, matrix_rot_z(ROT_Z_D));
		fdf_new_image(map);
	}
}

static void		key_hook_rot_y(int keycode, t_map *map)
{
	if (keycode == ROT_Y_U_KEY)
	{
		calc_matrix(map, matrix_rot_y(ROT_Y_U));
		fdf_new_image(map);
	}
	else if (keycode == ROT_Y_D_KEY)
	{
		calc_matrix(map, matrix_rot_y(ROT_Y_D));
		fdf_new_image(map);
	}
}

static void		key_hook_rot_x(int keycode, t_map *map)
{
	if (keycode == ROT_X_U_KEY)
	{
		calc_matrix(map, matrix_rot_x(ROT_X_U));
		fdf_new_image(map);
	}
	else if (keycode == ROT_X_D_KEY)
	{
		calc_matrix(map, matrix_rot_x(ROT_X_D));
		fdf_new_image(map);
	}
}

static void		key_hook_moove(int keycode, t_map *map)
{
	if (keycode == UP_KEY)
	{
		calc_matrix(map, matrix_traslat(0, UP, 0));
		fdf_new_image(map);
	}
	else if (keycode == DOWN_KEY)
	{
		calc_matrix(map, matrix_traslat(0, DOWN, 0));
		fdf_new_image(map);
	}
	else if (keycode == LEFT_KEY)
	{
		calc_matrix(map, matrix_traslat(LEFT, 0, 0));
		fdf_new_image(map);
	}
	else if (keycode == RIGHT_KEY)
	{
		calc_matrix(map, matrix_traslat(RIGHT, 0, 0));
		fdf_new_image(map);
	}
}

int				key_hook(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
	{
		ft_free_points(map->points, map->height);
		ft_free_points(map->pts_cpy, map->height);
		mlx_destroy_window(map->xx.mlx_ptr, map->xx.mlx_win);
		exit(0);
	}
	else if (keycode == RESET_KEY)
	{
		ft_free_points(map->points, map->height);
		if ((map->points = cpy_pts(map->pts_cpy, map->height, map->width))\
				== NULL)
			return (-1);
		set_init_map(map);
		fdf_new_image(map);
	}
	key_hook_moove(keycode, map);
	key_hook_zoom(keycode, map);
	key_hook_colors(keycode, map);
	key_hook_rot_x(keycode, map);
	key_hook_rot_y(keycode, map);
	key_hook_rot_z(keycode, map);
	return (0);
}
