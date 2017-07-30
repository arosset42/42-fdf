/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:06 by arosset           #+#    #+#             */
/*   Updated: 2017/07/29 18:11:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_usage(void)
{
	ft_putendl_fd("usage: ./fdf source_file.fdf", 2);
}

void	ft_error(int c, char *s)
{
	if (c == 1)
		ft_usage();
	if (c == 2)
	{
		ft_putstr_fd("./fdf ", 2);
		ft_putstr_fd(s, 2);
		ft_putendl_fd(" : invalid file", 2);
		ft_usage();
	}
	if (c == 3)
		ft_putendl_fd("./fdf: invalid map", 2);
	if (c == 4)
		ft_putendl_fd("Error malloc", 2);
	if (c == 42)
		ft_putendl_fd("Error GNL", 2);
	ft_printf("error = %d\n", c);
	exit(EXIT_FAILURE);
}
