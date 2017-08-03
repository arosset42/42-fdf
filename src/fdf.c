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


void 	ft_fdf(char *av)
{
	t_win	*screen;
	t_map	*map;

	if (!(screen = (t_win *)malloc(sizeof(t_win))))
		ft_error(4, 0);
	map = ft_parse_map(av, 0, NULL);
	if (map->len == 0 || map->lines[0]->len == 0)
		ft_error(3, 0);
	screen->map = map;
	get_center(screen);
	screen->color = choose_color();
	screen->cnum = 0;
	screen->scale_p = 0;
	ft_init_win(screen, WIN_W, WIN_H, "Arosset 42 FDF");
	adapt_map(screen);
	mlx_expose_hook(screen->win, ft_draw, screen);
	mlx_hook(screen->win, 2, 3, ft_key_hook, screen);
	mlx_loop(screen->mlx);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_fdf(av[1]);
	else
		ft_error(1, 0);
	return (0);
}
