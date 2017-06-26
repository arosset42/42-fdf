/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:50:12 by arosset           #+#    #+#             */
/*   Updated: 2017/06/26 14:50:14 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void 	set_pts(char *line, t_fdf *fdf)
{
	static	int		i;
	int				j;
	char			**tab;

	j = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[j])
	{
		ft_printf("tab[%d] = %s\n", j, tab[j]);
		// fdf->pts[i][j] = ft_atoi(tab[j]);
		// ft_printf("x = %d, y = %d, z = %d\n", fdf->pts[i], fdf->pts[i][j], fdf->pts[i][j][0]);
		j++;
	}
	i++;
}

static int 	check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (ft_isdigit(line[i]))
			i++;
		else if (line[i] == '-' && ft_isdigit(line[i + 1]) &&
					(line[i - 1] == ' ' || i == 0))
			i++;
		else
			return (0);
	}
	return (1);
}

char 	*read_check(char *av, t_fdf *fdf)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	fdf->dx = 1;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error(2);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(check_line(line)))
			ft_error(3);
		set_pts(line, fdf);
		break;
	}
	if (ret == -1)
		ft_error(42);
	return ("ok");
}
