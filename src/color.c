/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 17:19:03 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 17:19:05 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		find_color(t_color *spectrum, int z, double min, double max)
{
	int	t1;
	int	t2;
	int	color;

	if (z <= min)
		return (spectrum->c1);
	if (z >= max)
		return (spectrum->c2);
	t1 = spectrum->c1 / 256 / 256;
	t2 = spectrum->c2 / 256 / 256;
	color = ((((z - fabs(min)) * (t2 - t1)) /
				(max - fabs(min))) + t1) * 256 * 256;
	t1 = spectrum->c1 / 256 % 256;
	t2 = spectrum->c2 / 256 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1) * 256;
	t1 = spectrum->c1 % 256;
	t2 = spectrum->c2 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1);
	return (color);
}

int		get_color(t_win *pic, t_point *p1, t_point *p2, double alpha)
{
	t_color	c;
	int		color;

	if (ft_out_window(p1) == 1)
	{
		color = (p1->color * (1 - alpha)) + (p2->color * alpha);
		if (color < pic->map->min || color > pic->map->max)
			return (0);
		if (color <= pic->map->mid && color >= pic->map->min)
		{
			c.c1 = pic->color[pic->cnum][0];
			c.c2 = pic->color[pic->cnum][1];
			return (find_color(&c, color, pic->map->min, pic->map->mid));
		}
		else if (color <= pic->map->max && color >= pic->map->mid)
		{
			c.c1 = pic->color[pic->cnum][1];
			c.c2 = pic->color[pic->cnum][2];
			return (find_color(&c, color, pic->map->mid, pic->map->max));
		}
	}
	return (0);
}

int		*put_color(int a, int b, int c)
{
	int	*color;

	color = (int *)malloc(sizeof(int) * 3);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**choose_color(void)
{
	int		**color;

	color = malloc(sizeof(int *) * THEMES);
	color[0] = put_color(RGB_WHITE, RGB_WHITE, RGB_WHITE);
	color[1] = put_color(RGB_BLUE, RGB_LIME, RGB_RED);
	color[2] = put_color(RGB_BLUE, RGB_YELLOW, RGB_WHITE);
	color[3] = put_color(RGB_SCIBLUE, RGB_DEEPSKYBLUE, RGB_CREAMCAN);
	color[4] = put_color(RGB_BLUE, RGB_BROWN, RGB_WHITE);
	color[5] = put_color(RGB_BLUE, RGB_LIME, RGB_LIME);
	return (color);
}
