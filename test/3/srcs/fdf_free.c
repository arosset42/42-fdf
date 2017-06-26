/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:37:57 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/02 10:02:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_free_points(t_point **points, int h)
{
	int		y;

	y = -1;
	while (++y < h)
	{
		free(points[y]);
	}
	free(points);
	points = NULL;
}

void		ft_free_splitted(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split[i]);
	free(split);
	split = NULL;
}
