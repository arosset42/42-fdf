/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:20:20 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/03 16:03:09 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void				print_board(void)
{
	ft_putendl("\x1b[32m		KEYBOARD\x1b[0m");
	ft_putendl("\x1b[31mZoom:		\x1b[35m+ -\x1b[0m\x1b[0m");
	ft_putendl("\x1b[31mTraslation:	\x1b[35mArrows\x1b[0m\x1b[0m");
	ft_putendl("\x1b[36mX \x1b[31mrotation:	\x1b[35mQ A\x1b[0m\x1b[0m");
	ft_putendl("\x1b[36mY \x1b[31mrotation:	\x1b[35mW S\x1b[0m\x1b[0m");
	ft_putendl("\x1b[36mZ \x1b[31mrotation:	\x1b[35mE D\x1b[0m\x1b[0m");
	ft_putendl("\x1b[31mColors pad:\x1b[0m	\x1b[35m1 2 3 4\x1b[0m\x1b[0m");
	ft_putendl("\x1b[31mREset:\x1b[0m		\x1b[35m#1\x1b[0m\x1b[0m");
}

static int				fdf_init(t_mlx *xx)
{
	if ((xx->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((xx->mlx_win = mlx_new_window(xx->mlx_ptr, WIN_X, WIN_Y, "FDF")) \
			== NULL)
		return (-1);
	return (0);
}

int						fdf(t_map *map)
{
	if ((fdf_init(&map->xx)) < 0)
		return (-6);
	print_board();
	set_init_map(map);
	fdf_new_image(map);
	mlx_hook(map->xx.mlx_win, 2, 3, key_hook, map);
	mlx_loop(map->xx.mlx_ptr);
	return (0);
}
