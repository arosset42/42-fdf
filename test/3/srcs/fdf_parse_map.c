/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:40:04 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/04 11:06:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_width(char *line)
{
	int			i;
	int			v;
	int			count_w;

	i = -1;
	v = 0;
	count_w = 0;
	while (line[++i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (!v)
				++count_w;
			v = 1;
		}
		else
			v = 0;
	}
	return (count_w);
}

static int		fdf_width(int fd)
{
	int			ret;
	char		tmp;
	int			width;
	int			v;

	width = 0;
	v = 0;
	tmp = '\0';
	ret = 0;
	while (((ret = read(fd, &tmp, 1)) > 0) && (tmp != '\n'))
	{
		if (tmp >= '0' && tmp <= '9')
		{
			if (!v)
				++width;
			v = 1;
		}
		else
			v = 0;
	}
	return (width);
}

static int		fdf_height(int fd, int width)
{
	int			ret;
	int			height;
	char		*line;
	int			distorted_map;

	ret = 0;
	height = 0;
	line = NULL;
	distorted_map = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		//ft_putendl(line);
		if (width != check_width(line))
			distorted_map = 1;
		free(line);
		++height;
	}
	free(line);
	//ft_putchar('\n');
	if (distorted_map)
		ft_putendl("\x1b[33mWarning! Map may be distorted!\x1b[0m");
	return (height);
}

int				parse_map(char *file)
{
	t_map		*map;
	int			fd;

	map = NULL;
	fd = 1;
	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-2);
	if ((map->width = fdf_width(fd)) <= 0)
		return (-3);
	if (close(fd) < 0)
		return (-5);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-2);
	if ((map->height = fdf_height(fd, map->width)) <= 0)
		return (-3);
	ft_printf("HERE\n");
	if ((map->points = (t_point**)malloc(sizeof(t_point*) * map->height)) \
			== NULL)
		return (-1);
	map->distance = DIST;
	map->color = GREEN;
	if (close(fd) < 0)
		return (-5);
	return (get_map(map, file));
}
