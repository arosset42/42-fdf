/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:07:11 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:11:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		get_points(t_map *map, t_point points[map->width], \
		char **line, int y)
{
	int			x;

	x = -1;
	while (line[++x])
	{
		points[x].y = y;
		points[x].x = x;
		points[x].z = ft_getnbr(line[x]);
		points[x].s = 1;
	}
	return (0);
}

static int		get_line(t_map *map, int fd)
{
	char		*line;
	char		**splitted_line;
	int			y;

	line = NULL;
	splitted_line = NULL;
	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if ((map->points[y] = (t_point*)malloc(sizeof(t_point) * map->width)) \
				== NULL)
			return (-1);
		splitted_line = ft_strsplit(line, ' ');
		get_points(map, map->points[y], splitted_line, y);
		ft_free_splitted(splitted_line);
		free(line);
		++y;
	}
	free(line);
	line = NULL;
	return (0);
}

int				get_map(t_map *map, char *file)
{
	int			fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-2);
	if ((get_line(map, fd)) < 0)
		return (-1);
	if (close(fd) < 0)
		return (-5);
	if ((map->pts_cpy = cpy_pts(map->points, map->height, map->width)) == NULL)
		return (-1);
	return (fdf(map));
}
