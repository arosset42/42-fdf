/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:50:12 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 18:16:55 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_min_max(t_map *map)
{
	int		i;
	int		j;
	int		k;
	double	tmin;
	double	tmax;

	i = -1;
	while (++i < map->len)
	{
		j = -1;
		while (++j < map->lines[i]->len - 1)
		{
			k = j;
			while (++k < map->lines[i]->len)
			{
				tmin = ft_min(map->lines[i]->points[j]->z / SIZE_ALT,
						map->lines[i]->points[k]->z / SIZE_ALT);
				tmax = ft_max(map->lines[i]->points[j]->z / SIZE_ALT,
						map->lines[i]->points[k]->z / SIZE_ALT);
				map->min = ft_min(tmin, map->min);
				map->max = ft_max(tmax, map->max);
				map->mid = (map->min + map->max) / 2;
			}
		}
	}
}

int		ft_points(char *line, int nb_line, t_point ***array_points)
{
	char	**str_array;
	t_point	*point;
	int		i;

	str_array = ft_strsplit(line, ' ');
	i = 0;
	while (str_array[i] != 0)
		i++;
	if (!((*array_points) = (t_point **)malloc(sizeof(t_point) * i)))
		ft_error(4, 0);
	i = 0;
	while (str_array[i] != 0)
	{
		if (!(point = (t_point *)malloc(sizeof(t_point))))
			ft_error(4, 0);
		point->x = (double)(i * SIZE_W);
		point->y = (double)nb_line * SIZE_H;
		point->color = ft_atoi(str_array[i]);
		point->z = (double)(point->color) * SIZE_ALT;
		(*array_points)[i] = point;
		i++;
	}
	return (i);
}

int		ft_nb_line(char *av)
{
	int		fd;
	int		nb_line;
	char	buf;

	nb_line = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error(2, av);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_line++;
	}
	close(fd);
	return (nb_line);
}

void 	ft_verif_line(char *line, char *av)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]) && line[i] != '-')
			ft_error(3, av);
		i++;
	}
}

t_map	*ft_parse_map(char *av, int fd, char *line)
{
	t_map	*map;
	int		count;
	t_line	*row;
	t_point	**pts;

	count = 0;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))) ||
		!(map->lines = (t_line **)malloc(sizeof(t_line) * ft_nb_line(av))))
		ft_error(4, 0);
	map->len = 0;
	if ((fd = open(av, O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(row = (t_line *)malloc(sizeof(t_line))))
				ft_error(4, 0);
			ft_verif_line(line, av);
			row->len = ft_points(line, count, &pts);
			row->points = pts;
			map->lines[count++] = row;
		}
		map->len = count;
		ft_get_min_max(map);
	}
	return (map);
}
