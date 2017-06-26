/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:33:55 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/02 10:39:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(char *msg)
{
	ft_putstr("Error: ");
	ft_putendl(msg);
	exit(1);
}

int		ft_argv_error(void)
{
	return (ft_error("Wrong number of arguments."));
}

int		ft_malloc_error(void)
{
	return (ft_error("Failed to malloc."));
}

int		ft_map_error(int err)
{
	if (err == -1)
		return (ft_malloc_error());
	else if (err == -2)
		return (ft_error("Failed opening file."));
	else if (err == -3)
		return (ft_error("An error occurred while reading the map."));
	else if (err == -4)
		return (ft_error("Wrog map."));
	else if (err == -5)
		return (ft_error("Failed closing file."));
	else if (err == -6)
		return (ft_error("Failed initializing mlx."));
	else if (err == -10)
		return (ft_error("Failed creating window."));
	return (ft_error("An error occurred."));
}
