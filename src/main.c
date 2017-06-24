/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:16:29 by arosset           #+#    #+#             */
/*   Updated: 2017/06/23 14:16:31 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


int 	key_funct(int keycode, t_fdf *param)
{
	ft_printf("key event : %d\n", keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 124)
	{
		param->x += 10;
		mlx_clear_window(param->mlx, param->win);
		mlx_string_put(param->mlx, param->win, param->x, param->y+10, 0x003399FF, "coucou");
	}
	if (keycode == 125)
	{
		param->y += 10;
		mlx_clear_window(param->mlx, param->win);
		mlx_string_put(param->mlx, param->win, param->x, param->y+10, 0x003399FF, "coucou");
	}
	if (keycode == 123)
	{
		param->x -= 10;
		mlx_clear_window(param->mlx, param->win);
		mlx_string_put(param->mlx, param->win, param->x, param->y+10, 0x003399FF, "coucou");
	}
	if (keycode == 126)
	{
		param->y -= 10;
		mlx_clear_window(param->mlx, param->win);
		mlx_string_put(param->mlx, param->win, param->x, param->y+10, 0x003399FF, "coucou");
	}
	return (1);
}

int		main(void)
{
	t_fdf	*param;

	param->x = 100;
	param->y = 0;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 500, 500, "42 arosset");

	mlx_string_put(param->mlx, param->win, param->x, param->y, 0x00CC0000, "coucou");
	mlx_key_hook(param->win, key_funct, param);
	mlx_loop(param->mlx);
	return (0);
}
