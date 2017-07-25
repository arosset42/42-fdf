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
		printf("len = %d, min %f, max %f, mid %f\n",
		 			map->len, map->min, map->max, map->mid);
		screen->map = map;
		get_center(screen);
		printf("center x %f, center y %f\n", screen->center.x, screen->center.y);
		ft_init_win(screen, WIN_W, WIN_H, "42 FDF");
		adapt_map(screen);
		printf("Start draw\n");
		mlx_expose_hook(screen->win, ft_draw, screen);
		mlx_key_hook(screen->win, ft_key_hook, screen);
		mlx_loop(screen->mlx);
	}
	else
		ft_error(1, 0);
	return (0);
}
